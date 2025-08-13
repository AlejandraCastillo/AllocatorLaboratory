# 🔢 Allocator Laboratory

**Estado:** 🚧 En desarrollo

[English version](README.md)

## 🧠 Sobre este proyecto

Recientemente decidí cambiar mi enfoque de desarrollo Android hacia la programación de bajo nivel. Esta decisión trajo consigo varios desafíos: necesitaba un lenguaje más apropiado para este entorno, como C, y construir proyectos relevantes que reflejaran esta nueva dirección profesional.

**Allocator Laboratory** nace como respuesta a estas necesidades: un proyecto de impacto con el que puedo reconectar con la programación en C, explorar la lógica de sistemas, y al mismo tiempo exponerme como una programadora con capacidad de análisis, diseño y comprensión profunda de cómo funciona la memoria a bajo nivel.

## 🧩 ¿Qué es Allocator Laboratory?

Allocator Laboratory es una colección de **simuladores de allocadores de memoria**, diseñados para ser independientes entre sí. Cada allocador implementa una estrategia distinta de gestión de memoria, y todos operan sobre un bitmap simulado común.

El objetivo es ilustrar funcionalmente cómo se comporta cada tipo de allocador, sus ventajas, sus limitaciones, y sus diferencias frente a otros modelos.

## 🧮 Funcionalidades esperadas

Cada allocador deberá ser capaz de:

- Simular la asignación de bloques de memoria sobre una estructura abstracta.
    
- Liberar bloques previamente asignados.
    
- Mantener su propio estado interno para representar qué partes de la memoria están ocupadas o libres.
    
- Aplicar una estrategia coherente de gestión del espacio disponible.

Este proyecto no almacena ni interpreta datos reales: se centra únicamente en la lógica de asignación y liberación de memoria.

## 🛠️ Tecnologías utilizadas

- Lenguaje: **C**
    
- Entorno de desarrollo: **Visual Studio Code**
    
- Sistema de compilación: **Makefile** (planificado)
    
- Pruebas unitarias: Se implementarán pruebas para verificar el correcto funcionamiento de cada allocador
    
- Principios de diseño: Adaptación de los **principios SOLID** a la programación en C para mantener el código desacoplado y legible.

## ▶️ Cómo ejecutar el proyecto

### Requisitos del sistema

- Compilador de C (ej. `gcc`)
    
- Make (opcional, pero recomendado)
    
- Git

Instalación en sistemas basados en Unix:

```bash
sudo apt install build-essential git
```

### Clonar el proyecto

```bash
git clone https://github.com/tuusuario/allocator-laboratory.git
cd allocator-laboratory
make run
```

## 🗂️ Estructura del proyecto

```text
AllocatorLaboratory/
├── journal/                       # Diario técnico
│   ├── en/                        # Entradas en inglés
│   │   └── entries/
│   │   └── journal_index.md
│   └── es/                        # Entradas en español
│       └── entries/
│       └── journal_index.es.md
├── src/                           # Código fuente del proyecto
│   ├── core/                      # Infraestructura central
│   ├── allocators/                # Estrategias de asignadores de memoria
│   │   └── allocator.h            # Interfaz común para allocators
│   └── main.c                     # Punto de entrada
├── .gitignore
├── README.md                      # Versión en inglés
└── README.es.md                   # Versión en español

```

## 🎢 Ruta de alocadores

A continuación, la ruta que estoy siguiendo para construir mis allocadores, cada uno con creciente complejidad:

|Nivel|Nombre|Conceptos clave|Estado|
|---|---|---|---|
|1|Bloques fijos + bitmap|Fragmentación interna, bitmap, bloques fijos|⏳ En desarrollo|
|2|Free list (bloques variables)|Fragmentación externa, listas enlazadas|🔜 Por comenzar|
|3|Coalescing|Compactación, fusión de bloques libres|🔜 Por comenzar|
|4|Buddy allocator|Potencias de 2, recursividad, división/unión|🔜 Por comenzar|
|5|Slab / Pool allocator|Pools por tipo de objeto, eficiencia|🔜 Por comenzar|
|6|Arena allocator|Liberación grupal, rendimiento bruto|🔜 Por comenzar|
|7|Allocador mixto|Multi-estrategia adaptativa|🔜 Por comenzar|

Cada nivel será acompañado de:

- Explicación del diseño
    
- Diagrama visual de la memoria
    
- Decisiones de implementación
    
- Pruebas específicas

## 📖 Diario técnico

Llevo un registro narrativo de mis decisiones, descubrimientos y emociones a lo largo del proyecto.  
Este diario documenta tanto los avances técnicos como el camino personal que he recorrido.

📍 [Índice del diario técnico](./journal/es/journal_index.es.md)

## 🚀 Planes a futuro

Una vez finalizada esta ruta, planeo desarrollar una **aplicación para Android** en la que pueda integrar estos simuladores como herramientas pedagógicas para enseñar el funcionamiento de la memoria a nivel de sistema.

Será una app visual, interactiva y educativa, dirigida tanto a estudiantes como a personas curiosas por la computación a bajo nivel.

