# Systems Performance Toolkit Architecture

## Overview

The toolkit is divided into independent systems-level components.

```
Application
    |
    +---- Memory Allocator
    |
    +---- Bit Operations
    |
    +---- CPU Information
    |
    +---- Benchmark Engine
    |
    +---- Algorithms
```

## Memory
```
allocator.c
```
Provides a small abstraction over heap allocation and records allocation statistics.

## Bit Operations
```
bitops.c
```
Implements operations directly over integer representations using bitwise operators.

## CPU
```
cpu.c
```
Provides basic information about the execution environment.

## Benchmarking
```
benchmark.c
```
Provides a reusable timing interface for measuring computational workloads.

## Algorithms
```
algorithms.c
```
Contains workloads designed to investigate how memory-access patterns influence performance.

## Design Principle

The system separates measurement infrastructure from the workloads being measured.

This allows different algorithms to be benchmarked using the same interface.