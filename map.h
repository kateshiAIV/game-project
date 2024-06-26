#include <SFML\Graphics.hpp>
const int WIDTH_MAP = 78; // width of the map
const int HEIGHT_MAP = 75; // height of the map



sf::String TileMap[HEIGHT_MAP] = {
    "000000000000000000000000000000000000000000000000000000000000000000000000000000",
    "0                                                                            0",
    "0  -     +     -    -       -     zxcv   zxcv   zxcv        -     -          0",
    "0      +   -    +                 asdf   asdf   asdf       -                 0",
    "0    ++     -          ++ +   -   qwer   qwer   qwer      -        -         0",
    "0          -      +         +    +1234 + 1234+  1234     -                   0",
    "0     -                    -                                                 0",
    "0     9   8   9   77   7    7    9      8    9       8      8       7        0",
    "0       8   7   7    9         8     7    9      7       7     9      9      0",
    "0                                                                    -       0",
    "0                                                                9     -     0",
    "0                                                                            0",
    "0                                                                    8       0",
    "0                                                                  7         0",
    "0                                                                 9    -     0",
    "0                                                                   7        0",
    "0                                                                  8         0",
    "0                                                                  97        0",
    "0                                                                            0",
    "0                                                                  7         0",
    "0                                                                 7          0",
    "0                                                                  8         0",
    "0                                                                  8         0",
    "0                                                                 9          0",
    "0                                                                  7         0",
    "0                                                                7  7        0",
    "0                                                                  8         0",
    "0                                                               8   7  9     0",
    "0                                                                8           0",
    "0      ?  ?     ?                                                  9         0",
    "0       ??   ? ?   7    7     7 9    8       9   8        7      8    9      0",
    "0        ?  ???      8      8  8 7     8   9   7  88   8  9   8   7  8       0",
    "555555555??6?555555       9        7     7      7    7      9      8         0",
    "500000000????000005                                              7    8      0",
    "5?????????????????5          +                                    9          0",
    "5??5???????????5??5   +            +                               9         0",
    "5??0???5???????0??5             -        -    +                      8       0",
    "5??????0??????????5     +  +              -     =                            0",
    "5?????????????????5          +        +       +                    9         0",
    "5??5???????????5??5      -    -  #                    ioioioioio        ioioio",
    "5??0???????????0??5   +               +    -          klklklklklppppppppklklkl",
    "5?????????????????5       +      +       +     +      iohjhjhjhjpppppppphjhjio",
    "5555555555555555555     #                             klnmnmnmnmppppppppnmnmkl",
    "0000000000000000000    -    +         +    +    -     ioppppppppppppppppppppio",
    "0                         -  +          +     +       klppppppppppppppppppppkl",
    "0   $             +                -                  ioppppppppppppppppppppio",
    "0         +      +     +       - +        +           klppppppppppppppppppppkl",
    "0       +         -   +     -      +    +   -    -    oioioioioioioioioioioioi",
    "0             +            #     #            +       lklklklklklklklklklklklk",
    "0       +    -+      +       +        +               jhjhjhjhjhjhjhjhjhjhjhjh",
    "0             -        -          -    -                           -    -    0",
    "0      ?                   +                -           +    -               0",
    "0  ?    ??   ???                  -       +    +     ++      -     +         0",
    "0     ???????               +    =     +        -         +           +      0",
    "0   ???????????                                                              0",
    "05555??????5555555555555555555555555555555555555555555555555555555555555555550",
    "00000??????0000000000000000000000000000000000000000000000000000000000000000000",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "0????????????????????????????????????????????????????????????????????????????0",
    "000000000000000000000000000000000000000000000000000000000000000000000000000000",
};


