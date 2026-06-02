# Zephyr RTOS - praticidade para que desenvolve software e hardware

## Descrição

Este repositório disponibiliza um projeto exemplo utilizando o Zephyr RTOS.

Os slides apresentados no evento estão disponibilizados: [slides-seminario-iot-2026](./doc/slides-seminario-iot-2026.pdf)

Contém um manifest `west.yml` que importa parte dos projetos incluídos no Zephyr,
contendo suporte para targets NXP e STM32.

Além disso, há uma aplicação exemplo em `manifest/samples/shell`, que habilita
diversos drivers de periféricos, networking e seus menus na SHELL.

A seguir são disponibilizadas instruções para setup do ambiente de desenvolvimento.

## Dependências extras para gravação

O processo de gravação na placa pode ter dependências extras que não serão
instaladas pelo Zephyr devido às licenças de distribuição dos softwares.

Caso a etapa 'flash' falhe (pelo terminal ou VS Code), a mensagem de erro deve
indicar uma aplicação que não conseguiu encontrar.

Proceda com a instalação do software ou indicação de sua localização para o Zephyr.

Ao gravar utilizando a extensão para o VS Code tive erros mesmo com o LinkServer
instalado corretamente e funcionando pelo terminal.
Adicionei um argumento ao runner com o path para o executável e passou a funcionar.

> Runner: linkserver
>
> Args: --linkserver /opt/linkserver/LinkServer

## Setup para Linux - Terminal

Criar uma pasta para o projeto

```bash
mkdir events-iot-2026-zephyr
```

Inicializar `virtualenv` Python

```bash
cd events-iot-2026-zephyr

virtualenv .venv
source .venv/bin/activate
pip install west
```

Inicializar workspace e clonar projetos

```bash
west init -m https://github.com/matheusmbar/events-iot-2026-zephyr
west update
```

Para utilizar o manifest completo do Zephyr, substitua o primeiro comando por:

```bash
west init -m https://github.com/zephyrproject-rtos/zephyr
```

Instalar pacotes Python e SDK ARM Zephyr

```bash
west packages pip --install

west sdk install -t arm-zephyr-eabi
```

Compilar exemplo e gravar na placa

```bash
cd manifest/samples/shell
west build -b <board> .
west flash
```

Abrir um terminal serial para testar o exemplo rodando na placa

```bash
picocom /dev/ttyACM0 -b 115200
```

## Setup com VS Code

### Instalação da extensão

[IDE for Zephyr](https://marketplace.visualstudio.com/items?itemName=mylonics.zephyr-ide)

Buscar e instalar extensão

![00-ide-for-zephyr](./doc/vs-code-ext/00-ide-for-zephyr.png)

Visão geral do fluxo de configuração

![01-overview](./doc/vs-code-ext/01-overview.png)

Instalar dependências para o host

![02-host-tools](./doc/vs-code-ext/02-host-tools.png)

Clicar em "Install All Missing Packages"

![03-host-tools-install-missing](./doc/vs-code-ext/03-host-tools-install-missing.png)

## Inicializar workspace com manifesto deste repositório

Create New Workspace in Current Folder

![new-workspace](./doc/vs-code-workspace/00-new-workspace.png)

Workspace from Git

![01-workspace-from-git](./doc/vs-code-workspace/01-workspace-from-git.png)

Inserir URL do repositório

> <https://github.com/matheusmbar/events-iot-2026-zephyr>

![02-workspace-from-git-2](./doc/vs-code-workspace/02-workspace-from-git-2.png)

Workspace inicializado

![03-workspace-setup-ok](./doc/vs-code-workspace/03-workspace-setup-ok.png)

Importar o projeto exemplo:

- no menu lateral "PROJECTS", clicar no '+' (Add Project)
- Selecionar a pasta `manifest/sample/shell`

Ou selecione um sample do Zephyr em: `external/zephyr`

![04-add-project](./doc/vs-code-workspace/04-add-project.png)

Selecionar board:

- no menu lateral "PROJECTS", clicar em "Add Build"

![05-add-project-ok](./doc/vs-code-workspace/05-add-project-ok.png)

Para placas nativas do Zephyr: "Zephyr Directory Only", pular próxima etapa.

Para placa customizada neste repositório: "Zephyr Directory Only"

![06-add-build](./doc/vs-code-workspace/06-add-build.png)

Para placa customizada neste repositório: selecionar a pasta "manifest/boards/iot_2026_mcxa156"

![07-select-board-folder](./doc/vs-code-workspace/07-select-board-folder.png)

Buscar e selecionar placa desejada na lista

![08-select-board](./doc/vs-code-workspace/08-select-board.png)

Caso deseje gravar na placa, adicione um 'Runner' em 'PROJECTS' > "Add Runner".

Escolha uma opção na lista de gravadores suportados pela placa.

![10-add-runner-to-build](./doc/vs-code-workspace/10-add-runner-to-build.png)

No menu lateral "SHELL: BUILD", clicar em 'Build' para compilar o projeto para a placa.

![09-build](./doc/vs-code-workspace/09-build.png)

No menu lateral "SHELL: BUILD", clicar em 'Flash' para compilar o projeto para a placa.

![11-flash](./doc/vs-code-workspace/11-flash.png)

Abra um terminal serial para testar o projeto rodando na placa.

![12-test](./doc/vs-code-workspace/12-test.png)

## Inicializar workspace com manifesto do Zephyr

Esta extensão também pode ser utilizada para inicializar um projeto do zero,
com menus iterativos para escolher a versão do Zephyr, módulos necessários e
versão do SDK.

Após isto, basta selecionar um sample do Zephyr como template, que será
copiado para o seu repositório.

As etapas são similares às mostradas anteriormente, com algumas opções a mais.

![01-workspace](./doc/vs-code-workspace-full/01-workspace.png)

![02-workspace-from-zephyr](./doc/vs-code-workspace-full/02-workspace-from-zephyr.png)

![03-new-west](./doc/vs-code-workspace-full/03-new-west.png)

![04-minimal-zephyr](./doc/vs-code-workspace-full/04-minimal-zephyr.png)

![05-zephyr-version](./doc/vs-code-workspace-full/05-zephyr-version.png)

![06-sdk-version](./doc/vs-code-workspace-full/06-sdk-version.png)

Aqui é recomendado selecionar somente as toolchains necessárias para os targets
que serão utilizados, do contrário serão baixados e instalados muitos SDKs que
ocupam bastante armazenamento.

![07-select-toolchains](./doc/vs-code-workspace-full/07-select-toolchains.png)

Selecione `arm-zephyr-eabi` para targets ARM

![08-select-toolchains-b](./doc/vs-code-workspace-full/08-select-toolchains-b.png)

No menu lateral 'PROJECTS', clique em "Create Project From Template"

![09-project-from-template](./doc/vs-code-workspace-full/09-project-from-template.png)

Selecione um sample de interesse.

O repositório de Zephyr está em `external/zephyr`

![10-choose-template](./doc/vs-code-workspace-full/10-choose-template.png)

Projeto criado. Acesse o menu lateral da extensão para compilar e gravar no
target, como demonstrado em anteriormente.

![11-project-created](./doc/vs-code-workspace-full/11-project-created.png)
