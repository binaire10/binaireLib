#ifndef CONFIG_H
#define CONFIG_H

#undef defaultvalue
#undef unused
#undef undefined

#define defaultvalue {}
#define unused(X) static_cast<void>(X)
#define undefined 0

#endif // CONFIG_H
