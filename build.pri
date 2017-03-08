CONFIG  += c++14
CONFIG -= app_bundle qt

staticlib|dll {
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/lib/debug
    } else {
        DESTDIR = $$PWD/lib/release
    }
}
