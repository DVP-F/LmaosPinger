# Contributing and development rules  

This will cover not just contribution guidelines but also my general development rules for this project.  

## ToC  

* [Header](#contributing-and-development-rules)
  * [Table of Contents](#toc)
  * [Codebase Rules](#codebase-rules)
  * [Target for development](#target-for-development)

## Codebase rules  

1. No using WINAPI, WIN32, or any other platform-specific function.  
2. The following languages are banned from use:  
    C++  
    C#  
    Java  
    JS and derivatives  
    VB  
    Python unless reasonable and non-compiling  
3. Recommended languages include the following:  
    C  
    Rust  
    Zig  

## Target for development  

Arguably the most important thing is to know what the given application is intended to do.  
In this case, it's to send fully customizable packets in a given way.  

More concretely; I want to be able to do the following:  

* Target any IP or MAC on any interface  
* Select between several packet types and protocols  
* Use standardized prebuilt packets (including as a base to build on)  
* Query a set of actions to be performed in order inluding looping both until stopped and a given number of times  
* Use configuration files  
* Use commandline arguments  
* Use neither (TUI/CLI)  

Anything outside of this will be considered unneeded scope creep and not be implemented lest it's neat enough.  
