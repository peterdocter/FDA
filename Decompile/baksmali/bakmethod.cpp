//
// Created by F8LEFT on 2016/4/8.
//

#include <vm/Dalvik.h>
#include <c++/iomanip>
#include <libdex/DexCatch.h>
#include "bakMethod.h"

#define formatHex  hex << setfill('0')
#define formatInt(n) formatHex << setw(n)
#define formatBit8 formatInt(1)
#define formatByte formatInt(2)
#define formatWord formatInt(4)
#define formatDword formatInt(8)
#define formatAddr formatWord

bakMethod::bakMethod(const DexMethod *inmethod, const DexFile *index){
    pDexMethd = inmethod;
    assert(inmethod != NULL);assert(index != NULL);
    pDexMethd = inmethod;
    pDexFile = index;
    pDexMethodId = dexGetMethodId(pDexFile, pDexMethd->methodIdx);

    if (pDexMethd->codeOff) {
        pCode = dexGetCode(pDexFile, pDexMethd);
    } else pCode = NULL;
}

bool bakMethod::decompileIns(u4 insnIdx, string &rel, u4 &insWidth) {
    const u2* insns = pCode->insns;
    ostringstream ss;

    DecodedInstruction decInsn;
    dexDecodeInstruction(&insns[insnIdx], &decInsn);
    insWidth = dexGetWidthFromOpcode(decInsn.opcode);
    if (decInsn.opcode == OP_NOP) {
        u2 instr = insns[insnIdx];
        if (instr == kPackedSwitchSignature) {
            ss << " packed-switch-data (" << insWidth << " units)";
        } else if (instr == kSparseSwitchSignature) {
            ss << " sparse-switch-data (" << insWidth << " units)";
        } else if (instr == kArrayDataSignature) {
            ss << " array-data (" << insWidth << " units)";
        } else {
            ss << "nop";
        }
    } else {
        ss << dexGetOpcodeName(decInsn.opcode);
    }
    string tmp;
    if (decInsn.indexType != kIndexNone) {
        // 操作类型
        getInsString(tmp, &decInsn);
    }
    const char *insBuf = tmp.c_str();

    // 寄存器参数
    switch (dexGetFormatFromOpcode(decInsn.opcode)) {
        case kFmt10x:        // op
            break;
        case kFmt12x:        // op vA, vB
            ss << " v" << decInsn.vA << ", v" << decInsn.vB;
            break;
        case kFmt11n:        // op vA, #+B
            ss << " v" << decInsn.vA << ", 0x" << hex << decInsn.vB;
            break;
        case kFmt11x:        // op vAA
            ss << " v" << decInsn.vA;
            break;
        case kFmt10t:        // op +AA
        case kFmt20t:        // op +AAAA
        {
            s4 targ = (s4) decInsn.vA;
            ss << " " << formatWord  << insnIdx + targ;
        }
            break;
        case kFmt22x:        // op vAA, vBBBB
            ss << " v" << decInsn.vA << ", v" << decInsn.vB;
            break;
        case kFmt21t:        // op vAA, +BBBB
        {
            s4 targ = (s4) decInsn.vB;
            ss << " v" << decInsn.vA << ", " << setw(4) << setfill('0') << insnIdx + targ;
        }
            break;
        case kFmt21s:        // op vAA, #+BBBB
            ss << " v" << decInsn.vA << ", 0x" << hex << decInsn.vB;
            break;
        case kFmt21h:        // op vAA, #+BBBB0000[00000000]
            // The printed format varies a bit based on the actual opcode.
            if (decInsn.opcode == OP_CONST_HIGH16) {
                ss << " v" << decInsn.vA << ", 0x" << hex << decInsn.vB;
            } else {
                s8 value = ((s8) decInsn.vB) << 48;
                ss << " v" << decInsn.vA << value << decInsn.vB; //", #long %lld // #%x"
            }   // TODO fix it
            break;
        case kFmt21c:        // op vAA, thing@BBBB
        case kFmt31c:        // op vAA, thing@BBBBBBBB
            ss << " v" << decInsn.vA << ", " << insBuf;
            break;
        case kFmt23x:        // op vAA, vBB, vCC
            ss << " v" << decInsn.vA << ", v" << decInsn.vB << ", v" << decInsn.vC;
            break;
        case kFmt22b:        // op vAA, vBB, #+CC
            ss << " v" << decInsn.vA << ", v" << decInsn.vB << ", 0x"
                << formatByte << decInsn.vC;
            break;
        case kFmt22t:        // op vA, vB, +CCCC
        {
            s4 targ = (s4) decInsn.vC;
            ss << " v" << decInsn.vA << ", v" << decInsn.vB << ", "
                << formatWord << insnIdx + targ;
        }
            break;
        case kFmt22s:        // op vA, vB, #+CCCC
            ss << " v" << decInsn.vA << ", v" << decInsn.vB << ", 0x"
                << formatWord << decInsn.vC;
            break;
        case kFmt22c:        // op vA, vB, thing@CCCC
        case kFmt22cs:       // [opt] op vA, vB, field offset CCCC
            ss << " v" << decInsn.vA << ", v" << decInsn.vB << ", "<< insBuf;
            break;
        case kFmt30t:
            ss << " #" << formatDword << decInsn.vA;
            break;
        case kFmt31i:        // op vAA, #+BBBBBBBB
        {
            /* this is often, but not always, a float */
            union {
                float f;
                u4 i;
            } conv;
            conv.i = decInsn.vB;
            ss << " v" << decInsn.vA << ", #float " << conv.f << " // #"
                << formatDword << decInsn.vB;
        }
            break;
        case kFmt31t:       // op vAA, offset +BBBBBBBB
            ss << " v" << decInsn.vA << ", "
                    << formatDword << insnIdx + decInsn.vB;
            break;
        case kFmt32x:        // op vAAAA, vBBBB
            ss << " v" << decInsn.vA << ", v" << decInsn.vB;
            break;
        case kFmt35c:        // op {vC, vD, vE, vF, vG}, thing@BBBB
        case kFmt35ms:       // [opt] invoke-virtual+super
        case kFmt35mi:       // [opt] inline invoke
        {
            ss << " {";
            for (int i = 0; i < (int) decInsn.vA; i++) {
                if (i == 0)
                    ss << "v" << decInsn.arg[i];
                else
                    ss << ", v" << decInsn.arg[i];
            }
            ss << "}, " << insBuf;
        }
            break;
        case kFmt3rc:        // op {vCCCC .. v(CCCC+AA-1)}, thing@BBBB
        case kFmt3rms:       // [opt] invoke-virtual+super/range
        case kFmt3rmi:       // [opt] execute-inline/range
        {
            /*
             * This doesn't match the "dx" output when some of the args are
             * 64-bit values -- dx only shows the first register.
             */
            ss << " {";
            for (int i = 0; i < (int) decInsn.vA; i++) {
                if (i == 0)
                    ss << "v" << decInsn.vC + i;
                else
                    ss << ", " << decInsn.vC + i;
            }
            ss << "}, " << insBuf;
        }
            break;
        case kFmt51l:        // op vAA, #+BBBBBBBBBBBBBBBB
        {
            /* this is often, but not always, a double */
            union {
                double d;
                u8 j;
            } conv;
            conv.j = decInsn.vB_wide;
            ss << " v" << decInsn.vA << ", #double " << conv.d << " // #" << decInsn.vB_wide;
        }
            break;
        case kFmt00x:        // unknown op or breakpoint
            break;
        default:
            ss << " ???";
            break;
    }
    rel = ss.str();
    return true;
}

void bakMethod::getInsString(string &rel, const DecodedInstruction *pDecInsn) {
    int outSize;
    u4 index;
    u4 width;
    ostringstream buf;

    /* TODO: Make the index *always* be in field B, to simplify this code. */
    switch (dexGetFormatFromOpcode(pDecInsn->opcode)) {
        case kFmt20bc:
        case kFmt21c:
        case kFmt35c:
        case kFmt35ms:
        case kFmt3rc:
        case kFmt3rms:
        case kFmt35mi:
        case kFmt3rmi:
            index = pDecInsn->vB;
            width = 4;
            break;
        case kFmt31c:
            index = pDecInsn->vB;
            width = 8;
            break;
        case kFmt22c:
        case kFmt22cs:
            index = pDecInsn->vC;
            width = 4;
            break;
        default:
            index = 0;
            width = 4;
            break;
    }

    switch (pDecInsn->indexType) {
        case kIndexUnknown:
            /*
             * This function shouldn't ever get called for this type, but do
             * something sensible here, just to help with debugging.
             */
            buf << "<unknown-index>";
            break;
        case kIndexNone:
            /*
             * This function shouldn't ever get called for this type, but do
             * something sensible here, just to help with debugging.
             */
            buf << "<no-index>";
            break;
        case kIndexVaries:
            /*
             * This one should never show up in a dexdump, so no need to try
             * to get fancy here.
             */
            buf << "<index-varies>" << (hex) << index;
            break;
        case kIndexTypeRef:
            if (index < pDexFile->pHeader->typeIdsSize) {
                const char * typeName = dexStringByTypeIdx(pDexFile, index);
                buf << typeName;
            } else {
                buf << "<type?> // type@" << (hex) << index;
            }
            break;
        case kIndexStringRef:
            if (index < pDexFile->pHeader->stringIdsSize) {
                const char *str = dexStringById(pDexFile, index);
                buf << "\"" << str << "\"";
            } else {
                buf << "<string?> // string@" << (hex) << index;
            }
            break;
        case kIndexMethodRef:
        {
            const DexMethodId *mId = dexGetMethodId(pDexFile, index);
            const char *name = dexStringById(pDexFile, mId->nameIdx);
            const char *classDexs = dexStringByTypeIdx(pDexFile, mId->classIdx);
            const char *signature = dexCopyDescriptorFromMethodId(pDexFile, mId);
            buf << classDexs << "->" << name << signature;
            free((void*)signature);
        }
            break;
        case kIndexFieldRef:
        {
            const DexFieldId *fId = dexGetFieldId(pDexFile, index);
            const char *name = dexStringById(pDexFile, fId->nameIdx);
            const char *classDexs = dexStringByTypeIdx(pDexFile, fId->classIdx);
            const char *signature = dexStringByTypeIdx(pDexFile, fId->typeIdx);
            buf << classDexs << "->" << name << ":" << signature;
        }
            break;
        case kIndexInlineMethod:
            buf << "[%" << index << "]" << (hex) << index;
            break;
        case kIndexVtableOffset:
            buf << "[%" << index << "]" << (hex) << index;
            break;
        case kIndexFieldOffset:
            buf << "[obj+%" << (hex) << index;
            break;
        default:
            buf << "<?>";
            break;
    }

    rel = buf.str();
//    buf.str("");
    return;
}

bool bakMethod::decompileTries(u4 insnIdx, string &exception, u4 &start, u4 &end, u4 &addr) {
    if (pCode == NULL) return false;
    if (insnIdx >= pCode->triesSize) return false;

    const DexTry *pTries = dexGetTries(pCode);
    const DexTry *pTry = &pTries[insnIdx];
    start = pTry->startAddr;
    end = start + pTry->insnCount;
    DexCatchIterator iterator;
    dexCatchIteratorInit(&iterator, pCode, pTry->handlerOff);
    DexCatchHandler *handler = dexCatchIteratorNext(&iterator);
    if (handler != NULL) {
        exception = (handler->typeIdx == kDexNoIndex) ? "any;" :
                    dexStringByTypeIdx(pDexFile, handler->typeIdx);
        addr = handler->address;
    } else {
        exception = "?;";
        addr = 0;
    }
    return true;
}

bool bakMethod::getProto(string &des) {
    char *descriptor = dexCopyDescriptorFromMethodId(pDexFile, pDexMethodId);
    des = descriptor;
    free(descriptor);
    return true;
}

void bakMethod::decompile(vector<string> &decs) {
    string tmp;
    string tmp2;

    stringstream ss;

    // .method flag name proto
    getFlag(tmp);
    getProto(tmp2);
    ss << ".method " << tmp << getName() << tmp2;
    decs.push_back(ss.str());
    ss.str("");

    if (pCode) {
        ss << ".registers " << hex << pCode->registersSize;
        decs.push_back(ss.str());
        ss.str("");

        // instruction
        u4 insSize = getInsSize(), insIdx = 0, insWidth = 0;
        while (insIdx < insSize) {
            decompileIns(insIdx, tmp, insWidth);
            decs.push_back(tmp);
            insIdx += insWidth;
        }
        // tries
        u4 triesSize = getTriesSize(), treIdx = 0, start = 0, end = 0, addr = 0;
        while (treIdx < triesSize) {
            decompileTries(treIdx, tmp, start, end, addr);
            ss << ".catch " << tmp << " {:"
            << formatAddr << start
            << " .. :"
            << formatAddr << end
            << " } :"
            << formatAddr << addr;
            decs.push_back(ss.str());
            ss.str("");
            treIdx++;
        }
    }
    decs.push_back(".end method");
}

