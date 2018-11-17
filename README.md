# VSS-Core [![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)][gpl3] [![Build Status](https://api.travis-ci.com/VSS-SDK/VSS-Core.svg?branch=master)][travis]

[![Trello](https://img.shields.io/badge/Trello-SDK-blue.svg)][vss-sdk-trello]
[![Slack](https://img.shields.io/badge/Slack-Channel-551a8b.svg)][slack]
[![Slack](https://img.shields.io/badge/Whatsapp-Group-green.svg)][whatsapp]

O VSS-Core é uma biblioteca open-source que faz parte do VSS-SDK.
Contém interfaces de comunicação entre os projetos do SDK, modelos que representam o domínio do problema de futebol de robôs e métodos uteis. Os pacotes trafegam utilizando ZeroMQ e são serializados utilizando Protobuf.

Documentação [Wiki][wiki].

Mais informações podem ser encontradas em [VSS-SDK][vss-sdk].

## Instalação
```
$ sudo ./configure.sh
```

## Desenvolvimento
Compilando
```
$ sudo ./configure.sh development
$ cd build
$ ./tests
```

## Exemplos
Exemplo em C++: [VSS-SampleCpp][samplecpp]

# Licença

Esse código está sob licença [GNU GENERAL PUBLIC LICENSE Version 3][gpl3], cujo uma cópia em texto pode ser encontrada em [LICENSE.txt](LICENSE.txt).

Você pode utilizar esse código. Caso o faça, nos informe.

[gpl3]: http://www.gnu.org/licenses/gpl-3.0/
[vss-sdk]: http://sirlab.github.io/VSS-SDK
[samplecpp]: https://github.com/SIRLab/VSS-SampleCpp
[travis]: https://travis-ci.com/VSS-SDK/VSS-Core
[vss-sdk-trello]: https://trello.com/b/b4dVV6ug/vss-sdk
[slack]: https://vss-sdk.slack.com
[wiki]: https://github.com/SIRLab/VSS-Core/wiki
[whatsapp]: whatsapp://chat?code=ESqglT350Jd4GUi5BQLxEp
