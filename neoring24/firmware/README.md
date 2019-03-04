

## GeekFactory Shell Library Hack

On compilation you may encouter the following error:

```
In file included from .piolibdeps/GeekFactory Shell Library_ID1946/Shell.c:20:0:
.piolibdeps/GeekFactory Shell Library_ID1946/Shell.h:35:26: fatal error: avr/pgmspace.h: No such file or directory
#include <avr/pgmspace.h>
```

In order for the shell to work with ESP32. make the following change to ```Shell.c```:

From:
```
#ifdef ARDUINO
#include <Arduino.h>
#ifdef ESP8266
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif
#endif
```

To:
```
#include <pgmspace.h>
```