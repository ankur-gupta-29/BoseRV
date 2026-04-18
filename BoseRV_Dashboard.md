/# BoseRV Architectural Graph

Welcome to the **BoseRV Map of Content**. By connecting these concepts with Obsidian's wiki-links, Obsidian will now generate a dedicated constellation model of your processor in your Graph View!

## The Core Concept
The heart of this project is the [[BoseRV Processor]].

It is broken down into major architectural milestones:
- [[Module 1: Single-Cycle Datapath]]
- [[Module 2: Python Verification Framework]]
- [[Module 3: The 5-Stage Pipeline]]
- [[Module 4: Hazard Handling]]
- [[Module 6: Cache Hierarchy]]
- [[Module 9: Virtual Memory & TLB]]
- [[Module 10: Linux Boot]]

---

## Technical Hardware Details

### [[Module 1: Single-Cycle Datapath]]
This module glues the physical hardware together:
- **Compute:** The [[ALU]] does the math (ADD, SUB, AND).
- **Brain:** The [[Control Unit Decoder]] tells the ALU what to do based on the instruction.
- **State:** The [[Register File]] holds variables.
- **Hierarchy:** Everything is glued together inside [[Top-Level Integration]].

### [[Module 2: Python Verification Framework]]
We test the hardware dynamically using industry-standard simulation:
- **Engine:** [[Verilator Compiler]] turns Verilog into C++.
- **Runner:** [[Pytest]] executes the test suite.
- **Framework:** [[Cocotb]] injects high-level Python commands into the raw hardware wires!

---
*Graph Tips: Open your Obsidian Graph View and search for `path:BoseRV` in the search bar. This will filter out all your PhD notes and give you an isolated, floating 3D map of your custom processor architecture!*
