
#include "mil/mil.hpp"

struct A {
    MIL_BEGIN(A);
    MIL_DECLARE_FIELD(int, a0);
    MIL_DECLARE_FIELD(int, a1);
    MIL_DECLARE_FIELD(int, a2);
    MIL_DECLARE_FIELD(int, a3);
    MIL_DECLARE_FIELD(int, a4);
    MIL_DECLARE_FIELD(int, a5);
    MIL_DECLARE_FIELD(int, a6);
    MIL_DECLARE_FIELD(int, a7);
    MIL_DECLARE_FIELD(int, a8);
    MIL_DECLARE_FIELD(int, a9);
    MIL_DECLARE_FIELD(int, a10);
    MIL_DECLARE_FIELD(int, a11);
    MIL_DECLARE_FIELD(int, a12);
    MIL_DECLARE_FIELD(int, a13);
    MIL_DECLARE_FIELD(int, a14);
    MIL_DECLARE_FIELD(int, a15);
    MIL_DECLARE_FIELD(int, a16);
    MIL_DECLARE_FIELD(int, a17);
    MIL_DECLARE_FIELD(int, a18);
    MIL_DECLARE_FIELD(int, a19);
    MIL_DECLARE_FIELD(int, a20);
    MIL_DECLARE_FIELD(int, a21);
    MIL_DECLARE_FIELD(int, a22);
    MIL_DECLARE_FIELD(int, a23);
    MIL_DECLARE_FIELD(int, a24);
    MIL_DECLARE_FIELD(int, a25);
    MIL_DECLARE_FIELD(int, a26);
    MIL_DECLARE_FIELD(int, a27);
    MIL_DECLARE_FIELD(int, a28);
    MIL_DECLARE_FIELD(int, a29);
    MIL_DECLARE_FIELD(int, a30);
    MIL_DECLARE_FIELD(int, a31);
    MIL_DECLARE_FIELD(int, a32);
    MIL_DECLARE_FIELD(int, a33);
    MIL_DECLARE_FIELD(int, a34);
    MIL_DECLARE_FIELD(int, a35);
    MIL_DECLARE_FIELD(int, a36);
    MIL_DECLARE_FIELD(int, a37);
    MIL_DECLARE_FIELD(int, a38);
    MIL_DECLARE_FIELD(int, a39);
    MIL_DECLARE_FIELD(int, a40);
    MIL_DECLARE_FIELD(int, a41);
    MIL_DECLARE_FIELD(int, a42);
    MIL_DECLARE_FIELD(int, a43);
    MIL_DECLARE_FIELD(int, a44);
    MIL_DECLARE_FIELD(int, a45);
    MIL_DECLARE_FIELD(int, a46);
    MIL_DECLARE_FIELD(int, a47);
    MIL_DECLARE_FIELD(int, a48);
    MIL_DECLARE_FIELD(int, a49);
    MIL_DECLARE_FIELD(int, a50);
    MIL_DECLARE_FIELD(int, a51);
    MIL_DECLARE_FIELD(int, a52);
    MIL_DECLARE_FIELD(int, a53);
    MIL_DECLARE_FIELD(int, a54);
    MIL_DECLARE_FIELD(int, a55);
    MIL_DECLARE_FIELD(int, a56);
    MIL_DECLARE_FIELD(int, a57);
    MIL_DECLARE_FIELD(int, a58);
    MIL_DECLARE_FIELD(int, a59);
    MIL_DECLARE_FIELD(int, a60);
    MIL_DECLARE_FIELD(int, a61);
    MIL_DECLARE_FIELD(int, a62);
    MIL_DECLARE_FIELD(int, a63);
    MIL_END;
};

int main() {
    mil::class_info<A>().fields();
}
