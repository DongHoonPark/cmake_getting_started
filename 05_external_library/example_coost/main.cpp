#include "co/flag.h"
#include "co/cout.h"

DEF_bool(x, false, "x");
DEF_bool(y, true, "y");
DEF_bool(debug, false, "dbg", d);
DEF_uint32(u, 0, "xxx");
DEF_string(s, "", "xx");

int main(int argc, char** argv) {
    flag::parse(argc, argv);
    cout << "x: " << FLG_x << '\n';
    cout << "y: " << FLG_y << '\n';
    cout << "debug: " << FLG_debug << '\n';
    cout << "u: " << FLG_u << '\n';
    cout << FLG_s << "|" << FLG_s.size() << '\n';
    return 0;
}