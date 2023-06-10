```mermaid
erDiagram;
    User ||--o{ Vehicle : owns
    Vehicle ||--o{ Location : is tracked at
    Vehicle ||--o{ Trip : makes
    Location ||--o{ Trip : starts
    Location ||--o{ Trip : ends
```
