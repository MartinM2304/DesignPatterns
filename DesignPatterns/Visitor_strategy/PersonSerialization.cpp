#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Person;
class Student;
class Teacher;

// Интерфейс Visitor
// Дефинира метод visit за всеки тип елемент, който може да бъде посетен.
class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(Person& person) = 0;
    virtual void visit(Student& student) = 0;
    virtual void visit(Teacher& teacher) = 0;
};

//Интерфейс Visitable (Елемент)
// Дефинира метод accept, който приема Visitor.
// Чрез този метод, указва на visitor-a кой тип е посещавания елемент
class Visitable {
public:
    virtual ~Visitable() = default;
    virtual void accept(Visitor& visitor) = 0;
};

class Person : public Visitable {
public:
    std::string name;
    int age;

    Person(const std::string& n, int a) : name(n), age(a) {}

    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};

class Student : public Person {
public:
    int fn;

    Student(const std::string& n, int a, int f) : Person(n, a), fn(f) {}

    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};

class Teacher : public Person {
public:
    int teacher_id;

    Teacher(const std::string& n, int a, int id) : Person(n, a), teacher_id(id) {}

    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
};

// Конкретни Посетители (Сериализатори
// Имплементират Visitor и дефинират конкретната операция (сериализация).

class CSVSerializerVisitor : public Visitor {
private:
    std::ostream& out;
public:
    CSVSerializerVisitor(std::ostream& os) : out(os) {}

    void visit(Person& person) override {
        out << "Person," << person.name << "," << person.age << "\n";
    }

    void visit(Student& student) override {
        out << "Student," << student.name << "," << student.age << "," << student.fn << "\n";
    }

    void visit(Teacher& teacher) override {
        out << "Teacher," << teacher.name << "," << teacher.age << "," << teacher.teacher_id << "\n";
    }
};

class BinarySerializerVisitor : public Visitor {
private:
    std::ostream& out;

    template<typename T>
    void write_binary(const T& value) {
        out.write(reinterpret_cast<const char*>(&value), sizeof(T));
    }

    void write_string(const std::string& str) {
        size_t len = str.length();
        write_binary(len);
        out.write(str.c_str(), len);
    }

public:
    BinarySerializerVisitor(std::ostream& os) : out(os) {}

    void visit(Person& person) override {
        char type = 'P';
        write_binary(type);
        write_string(person.name);
        write_binary(person.age);
    }

    void visit(Student& student) override {
        char type = 'S';
        write_binary(type);
        write_string(student.name);
        write_binary(student.age);
        write_binary(student.fn);
    }

    void visit(Teacher& teacher) override {
        char type = 'T';
        write_binary(type);
        write_string(teacher.name);
        write_binary(teacher.age);
        write_binary(teacher.teacher_id);
    }
};