# TCP Client-Server Communication Framework (C++20, ASIO)

This project is a lightweight and highly customizable framework for TCP communication between client and server. Built using C++20 and ASIO, it provides secure client authentication via challenge/response and guarantees efficient message ordering and processing with low server resource utilization.

## Features

- **Header-Only Design**: Easy to integrate into any project by simply including the relevant headers.
- **Client-Side Challenge**: The server requires clients to solve a challenge upon connection, ensuring only valid clients can communicate.
- **Generic Message Handling**: Message types are customizable using C++ templates, allowing flexibility for different applications.
- **Thread-Safe Message Queue**: A custom queue ensures that incoming and outgoing messages are processed in the correct order.
- **Asynchronous Operations**: Fully asynchronous, leveraging mutexes to maintain message order while utilizing a single CPU core efficiently.
- **Memory Management**: Smart pointers guarantee no memory leaks, even in multi-threaded environments.
- **Smart Wait**: Reduces server utilization to zero during idle periods, awakening only when new messages are received.
- **Multiplayer Ready**: Ideal for multiplayer games or real-time applications where multiple clients need to communicate with a single server.

## Use Cases

- Multiplayer games where the server coordinates messages between multiple clients.
- Any application requiring secure client-server communication with minimal resource usage and efficient message handling.

## Requirements

- C++20 compiler
- ASIO (Asynchronous I/O)

## Installation

- clone the repository
- add ASIO `\include` path address to project `Include Directories`
