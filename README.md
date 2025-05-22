# Design Patterns

Дизайн патърните се разделят на 3 основни вида:
- Creational;
- Behavioural;
- Structural;

**Creational** - осигуряват създаването на обекти, като скриват логиката по тяхното създаване;

**Behavioural** - отговарят за комуникацията между различни видове обекти;

**Structural** - начин за създаване на по-сложни обекти, използвайки инструменти като наследяване и композиция;

## Creational Design Patterns

### Factory

### Singleton

- Осигуряваме само една инстанция на даден клас, към която има глобален достъп
- Едно място, което да достъпваме

**Пример:** База данни

```c++
static Singleton& getInstance()
{
	static Singleton instance;
	return instance;
}
```

- Плюсове:
	- Само една инстанция на даден клас;
	- Глобален достъп;
	- Lazy инициализация - обектът се създава при достъпване на обекта;

- Минуси:
	- Multithreading - трябва да подсигурим, че няма да се достигне до **race condition**;
	- Често се определя като anti-pattern;

### Builder

- В някои ситуации искаме да ни е предоставена възможност даден клас да го инициализираме постъпково, спрямо това какви параметри са ни дадени
- Използва се, когато:
	- Имаме много наброй конструктори;
	- Имаме конструктори с много наброй параметри;

### Prototype

- Съзадаване на копие на обекти, без да се интересуваме от техния тип - **clone()**

## Behavioural Design Patterns

### Command

### Iterator

- При наличието на по-сложни структури от данни (хеш мап, дърво и т.н), ние бихме искали да скрием логиката по тяхното обхождане

### Visitor

### Strategy

## Structural Design Patterns

### Flyweight

# SOLID

## Single Responsibility Principle

## Open-closed Principle

## Liskov Substitution Principle

## Interface Segregation Principle

## Dependency Inversion Principle
