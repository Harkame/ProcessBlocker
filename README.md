# ProcessBlocker
Program that kill process regularly

# Requirements

-   Windows

## Installation

``` bash

make

```

## Usage


``` bash

pb.exe ProcessName process_to_block.exe another_process_to_block.exe ...

```

At runtime, it will create an new key in SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run with current arguments to make this program run at computer start
