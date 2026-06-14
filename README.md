# Aster Engine

Aster Engine is a lightweight 2D software rendering engine written in C.  
It is built from scratch using a custom framebuffer and manual rasterization, without relying on hardware graphics APIs such as OpenGL or DirectX.

The goal of this project is to understand how a rendering engine works at a low level by implementing the full rendering pipeline on the CPU.

---

## 🎯 Objective

This project focuses on exploring core graphics and engine concepts:

- Software rendering pipeline
- Framebuffer manipulation
- Rasterization algorithms
- Basic engine architecture design
- Low-level programming with Win32 API

---

## ⚙️ Technical Overview

- Language: C
- Platform: Windows (Win32 API)
- Rendering: CPU-based software framebuffer
- Pixel format: 32-bit ARGB
- No external graphics API (no OpenGL / DirectX)

---

## 🧠 Architecture

The engine is structured in layered components:

```
Platform Layer (Win32)  
↓  
Framebuffer  
↓  
Renderer (primitives, rasterization)  
↓  
World Layer (camera, tilemap, collision)  
```
  
  
  
### 📁 Planned structure

```
AsterEngine/  
├── src/  
│   ├── core/  
│   ├── platform/  
│   ├── graphics/  
│   ├── math/  
│   └── world/  
├── include/  
├── assets/  
├── build/  
└── README.md  
```

---

## 📦 Status

🚧 Work in progress — early development stage

---

## 📄 License

MIT License
