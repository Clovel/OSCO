# Contributing to OSCO
Contribution are always welcome ! 
Feel free to study the code to add to it or to fix it, report issues and make merge requests.

## Rules
The rules are basic : 
- Fork the project if ou want to change it. 
- Make pull requests
- Base your pull requests and branches on an issue

> NOTE : Please do not file an issue to ask a question before having 
> at least looked at opened/closed issues or the documentation.

## How can I contribute ?
- Testing
  - Features
  - Targets
    - Windows
    - Linux
    - macOS
    - ARM (Raspberry Pi for example)
    - Other embedded systems
- Documenting
  - Documents
  - Specifications
  - Design
  - Guidelines
  - Examples
  - Doxygen comments
- Answering questions
  - Taking part in the conversations taking place in the issues or merge requests
- Peer reviews in merge requests (MR)
- Checking compliance with the CANOpen protocol
- **And of course : CODE**
  - Locate bugs, inconsistencies, typos
  - Implementing new features
  - Implementing APIs for other languages
- And more !

## Coding rules
Other than the various APIs we can create for various languages,
the main code is in C.

For the detailed design and documentation of the project, Doxygen is used.
Please try to keep your code's doxygen comments up to date.

### The main code
- Comment your code as much as possible.
- Avoid over-complicated code when a easier to understand method is available.

### The APIs
Create APIs for you prefered language !
Try providing documentation and maybe an example (the examples subdirectory was made for this !).
Try complying as closely to the C API as possible to avoid confusion when switching from an API to another. 
