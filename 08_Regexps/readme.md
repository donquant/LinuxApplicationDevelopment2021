Конфигурируется всё это безобразие с помощью `autoreconf -fsiv`.
Далее `./configure` и `make`.

Т.к. в задании стояла задача эмулировать `echo 'string' | sed -E 's/regexp/substitution/'`, 
то и запускать программу предполагается следующим образом `./esub 'regexp' 'substitution' 'string'` 
