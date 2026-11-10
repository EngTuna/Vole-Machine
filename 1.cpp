class ALU {
public:
    // 1. الجمع بالمتمم الثنائي (Signed Addition - Opcode 5)
    Byte addSigned(Byte a, Byte b) {
        return (Byte)((int)a + (int)b);
    }

    // 2. الجمع بالفاصلة العائمة 8-bit (8-bit Float Addition - Opcode 6)
    // (تمثيل مبسط بناءً على متطلبات المادة)
    Byte addFloat8Bit(Byte a, Byte b) {
        // سيتم ربطها بخوارزمية الفاصلة العائمة المعتمدة في التقرير
        return a + b; 
    }

    // 3. العملية المنطقية OR (Opcode 7)
    Byte bitwiseOr(Byte a, Byte b) {
        return a | b;
    }

    // 4. العملية المنطقية AND (Opcode 8)
    Byte bitwiseAnd(Byte a, Byte b) {
        return a & b;
    }

    // 5. العملية المنطقية XOR (Opcode 9)
    Byte bitwiseXor(Byte a, Byte b) {
        return a ^ b;
    }

    // 6. التدوير الدائري لليمين (Circular Right Rotation - Opcode A)
    Byte rotateRight(Byte value, int count) {
        count = count % 8; // لأن البايت 8 بت
        return (value >> count) | (value << (8 - count));
    }
};