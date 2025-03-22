# TamanduContext

[![Latest Release](https://img.shields.io/github/v/release/Tamandutech/TamanduContext)](https://github.com/Tamandutech/TamanduContext/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/alexandrehiroyuki/library/TamanduContext.svg)](https://registry.platformio.org/libraries/alexandrehiroyuki/TamanduContext)
[![Latest Release Date](https://img.shields.io/github/release-date/Tamandutech/TamanduContext)](https://github.com/Tamandutech/TamanduContext/releases)
[![Last Commit Date](https://img.shields.io/github/last-commit/Tamandutech/TamanduContext)](https://github.com/Tamandutech/TamanduContext/commits/master)

[![GitHub Stars](https://img.shields.io/github/stars/Tamandutech/TamanduContext?style=flat&color=yellow)](https://github.com/Tamandutech/TamanduContext/stargazers)
[![Contributors](https://img.shields.io/github/contributors-anon/Tamandutech/TamanduContext)](https://github.com/Tamandutech/TamanduContext/graphs/contributors)
[![Top Language](https://img.shields.io/github/languages/top/Tamandutech/TamanduContext)](https://github.com/Tamandutech/TamanduContext)

## Description

Manage data shared by parallel processes in your embedded device.

## Getting Started

Use the [PlatformIO Registry](https://registry.platformio.org/libraries/alexandrehiroyuki/DataTome) to install the library!

```sh
# 1. Open PlatformIO Core CLI
# 2. Change directory (cd) to the PlatformIO project where platformio.ini is located.
# 3. Install Data Tome library by running:

pio pkg install --library "alexandrehiroyuki/TamanduContext"
```

## Contributing

### Getting Started to Contribute

1. Clone the repository

```bash
git clone https://github.com/Tamandutech/TamanduContext.git
```

2. Install PlatformIO Core (CLI)

[PlatformIO Core](https://docs.platformio.org/en/latest/core/installation/index.html)

```bash
pip install platformio
```

3. Install PlatformIO IDE (VSCode with PlatformIO Extension)

[PlatformIO IDE](https://docs.platformio.org/en/latest/integration/ide/vscode.html)

4. Install the recommended extensions

Look at the `.vscode/extensions.json` file to see the recommended extensions.

> When you open the project in VSCode, it will automatically show the extensions to install.

5. Run the commands to install the dependencies and build the project

```bash
pio install
pio run -e esp32dev --target compiledb
```

### Testing

The library comes with a set of automated tests. Contributions should include tests to cover the new functionality and ensure that no regressions are introduced.

To run the tests on all configured environments, run:

```bash
pio test
```

To test the library on a desktop machine, use the `desktop` environment:

```bash
pio test -e desktop
```

If you wish to test the library on a specific board, configure the environment in `platformio.ini` and run the tests:

```bash
pio test -e <environment>
```
