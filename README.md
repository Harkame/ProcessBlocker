# ProcessBlocker

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/4972adff99e44f5bb420b930ca4addf3)](https://www.codacy.com/manual/Harkame/ProcessBlocker?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Harkame/ProcessBlocker&amp;utm_campaign=Badge_Grade)
[![Maintainability](https://api.codeclimate.com/v1/badges/13406b611a5651f66fa5/maintainability)](https://codeclimate.com/github/Harkame/ProcessBlocker/maintainability)

Program that kill process regularly (every 10s)

At start, this program will create a new key in « SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run » with current arguments to make this program run at computer start

## Requirements

-   Windows
-   g++

## Installation

``` bash

make

```

## Usage

``` bash

pb.exe <processBlockerProcessName> <processToBlock.exe> <anotherProcessToBlock.exe> ... <yetAnotherProcessToBlock.exe>

```

processBlockerProcessName : Name that will appear in processes list

processToBlock.exe, anotherProcessToBlock.exe, yetAnotherProcessToBlock.exe : Processes to block

### Example

``` bash

pb.exe WindowsSecurity atom.exe chrome.exe

```

Create a new process called « WindowsSecurity » that kill all processes whose name are « atom.exe » or « chrome.exe »
