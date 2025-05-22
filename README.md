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

- Статична функция, обвита в клас, която на база някакъв аргумент/и, връща инстанция на даден клас
- Генерално създаване на обекти;

**Пример:**

```c++
class Factory
{
public:
	static Base* baseFactory(...);
}

Base* Factory::baseFactory(...)
{
	// ...
}

// Извикване
Base* ptr = Factory::baseFactory(...);
```

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

- В някои ситуации искаме да ни е предоставена възможност даден клас да го инициализираме постъпково;
- Решава някои проблеми на **Factory** за класове с много атрибути, от които много са **optional**;
- За да си гарантираме инициализиране на всички задължителни параметри, трябва **Builder** класът ни да има публичен конструктор
с всички задължителни атрибути като параметри, и **setter** методи за всички опционални параметри;

### Prototype

- Създаване на копие на обекти, без да се интересуваме от техния тип - **clone()**

**Пример:**

```c++
struct Base
{
public:
	virtual Base* clone() const = 0;
	virtual ~Base() noexcept = default;
}

struct Der : Base
{
public:
	virtual Base* clone() const override;
}

Base* Der::clone() const
{
	return new Der(*this);
}
```

## Behavioural Design Patterns

### Command

- Програма, която получава заявки

```console
> create <...>
> find <...>
> print <...>
```

```plaintext
							Command
						virtual execute() = 0;
		/					|					\
	CreateCommand				FindCommand				PrintCommand
	execute() override;			execute() override;			execute() override;
```

```c++
while (true)
{
	Command* current = CommandFactory::commandFactory(...);
	current->execute();
}
```

### Iterator

- Начин за обхождане на колекция, без да се интересуваме каква е тя;
- **Итератор** - указател към конкретен елемент;

- При имплементацията на итератор, задължително трябва да са налични следните оператори:
	- `operator++`, `operator--`, `operator+=`, `operator-=` - указателна аритметика;
	- `operator*` - връща стойността на текущия елемент;
	- `operator->` - връща указател на текущия елемент;
	- `operator==`, `operator!=` - проверки за достигане до края на колекцията;
	
- Колекциите трябва да имат следния интерфейс:
	- `begin()` - връща итератор към началото на колекцията;
	- `end()` – връща итератор към края на колекцията;
	
- Ако искаме да достъпваме елементи на произволни позиции, можем да имплементираме:
	- `operator[]`;
	- `operator+`;
	- `operator-`;

**Пример:**

```c++
template <typename T>
bool search(const T* arr, const T& elem)
{
	const T* iter = arr;
	
	while (iter != nullptr)
	{
		if (*iter == elem)
		{
			return true;
		}
		
		iter++;
	}
	
	return false;
}
```

### Visitor

- Взаимно разпознаване и взаимодействие на обекти от полиморфна йерархия, без да се чупи абстракцията

### Strategy

## Structural Design Patterns

### Flyweight

- Събира повече обекти в паметта, като споделя общите им ресурси
- Подобрява бързодействието, ако създаването на обекти е тежка операция
- Обектите са **immutable**!
- Реализация: **хеш / дърво**

# SOLID

5 принципа, които улесняват разработката на софтуера

## Single Responsibility Principle

- Класът трябва да отговаря само за една основна задача

**Пример:** E-Commerce

```c++
class Basket
{
	add();
	remove();
	// ...
	pay(); // Количката не отговаря за механизмите, по които се извършва плащане
}
```

![SRP](assets/srp.webp)

## Open-closed Principle

- Обектите трябва да са отворени за разширение, но затворени за промяна
- Полиморфизъм

![OCP](assets/ocp.webp)

## Liskov Substitution Principle

- Лисков е жена!!!
- Детето трябва да се държи като родителя си, без да променя параметри на връщане, липсващи функции, exception safety

## Interface Segregation Principle

## Dependency Inversion Principle
