class InstructionDecoder {
public:
    // دالة للتحقق مما إذا كان الـ Opcode مدعوماً (من 1 إلى C)
    bool isValid(Word raw) {
        char op = (raw >> 12) & 0x0F;
        return (op >= 1 && op <= 9) || (op >= 'A' && op <= 'C') || (op >= 10 && op <= 12);
    }

    // دالة فك الشفرة واستخراج الكائن
    Instruction decode(Word raw) {
        char opcode = (raw >> 12) & 0x0F;
        // تحويل الرقم إلى حرف ست عشري مظبوط (مثلاً لو 10 يبقى A وهكذا)
        if (opcode >= 10 && opcode <= 15) {
            opcode = 'A' + (opcode - 10);
        } else {
            opcode = '0' + opcode;
        }

        int r = (raw >> 8) & 0x0F;
        int s = (raw >> 4) & 0x0F;
        int t = raw & 0x0F;
        Byte operand = raw & 0xFF; // آخر 8 بت (للأوامر اللي زي 1, 2, 3, B)

        return Instruction(raw, opcode, r, s, t, operand);
    }
};