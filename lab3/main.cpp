#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <string>
#include <limits>
#include <memory> 
#include <iomanip>

using namespace std;

class BonusStrategy {
public:
    virtual double getOpeningBonus() const = 0;
    virtual double getDepositBonus() const = 0;
    virtual ~BonusStrategy() = default;
};

class MaleBonusStrategy : public BonusStrategy {
public:
    double getOpeningBonus() const override { return -420000; }
    double getDepositBonus() const override { return -15000; }
};

class FemaleBonusStrategy : public BonusStrategy {
public:
    double getOpeningBonus() const override { return 420000; }
    double getDepositBonus() const override { return 15000; }
};

bool isInt(int& x) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    if (cin.peek() != '\n') {
        cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

bool isDouble(double& x) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    if (cin.peek() != '\n') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

class Contribution
{
private:
    double size;
    unique_ptr<BonusStrategy> bonusStrategy;

public:
    Contribution() : size(0) {}

    void setBonusStrategy(unique_ptr<BonusStrategy> strategy) {
        bonusStrategy = move(strategy);
    }

    void addToContribution(double sum) {
        if (sum > 0) {
            double bonus = 0;
            if (bonusStrategy) {
                bonus = bonusStrategy->getDepositBonus();
                cout << "Бонус за пополнение: " << fixed << setprecision(2) << bonus << " руб." << endl;
            }

            size += sum + bonus;
            cout << "Вклад пополнен на " << fixed << setprecision(2) << sum << " руб. Текущая сумма: " << fixed << setprecision(2) << size << " руб." << endl;
        }
        else {
            cout << "Ошибка: сумма должна быть положительной!" << endl;
        }
    }

    void applyOpeningBonus() {
        if (bonusStrategy) {
            double bonus = bonusStrategy->getOpeningBonus();
            size += bonus;
            cout << "Бонус при открытии: " << fixed << setprecision(2) << bonus << " руб." << endl;
            cout << "Итоговая сумма после бонуса: " << fixed << setprecision(2) << size << " руб." << endl;
        }
    }

    void displayContribution() const {
        cout << "Deposit: " << fixed << setprecision(2) << size << " руб." << endl;
    }

    double getSize() const { return size; }
};

class Person
{
private:
    string name;
    int age;
    string gender;

public:
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }

    Person(const string& personName, const int& personAge, const string& personGender)
        : name(personName), age(personAge), gender(personGender) {
    }

    
    virtual bool interact() {
        cout << "\n=== Взаимодействие с " << name << " ===" << endl;
        cout << "Привет, " << name << "!" << endl;
        cout << "Хочешь стать вкладчиком нашего банка? (1 - да, 0 - нет): ";

        int choice;
        while (true) {
            cin >> choice;
            if (isInt(choice) && (choice == 0 || choice == 1)) {
                break;
            }
            cout << "Пожалуйста, введите 1 (да) или 0 (нет): ";
        }

        if (choice == 1) {
            cout << "Отлично! Давай сделаем тебя вкладчиком!" << endl;
            return true; // Стать вкладчиком
        }
        else {
            cout << "Жаль! Возвращайся, когда передумаешь!" << endl;
            return false; // Не становиться вкладчиком
        }
    }

    virtual void display1() const {
        cout << "Person: " << name << ", Age: " << age << ", Gender: " << gender << endl;
    }

    virtual ~Person() = default;
};

class Depositor : public Person
{
private:
    Contribution contribution;
    bool hasInteracted;

public:
    Depositor(const string& personName, int personAge, const string& personGender)
        : Person(personName, personAge, personGender), hasInteracted(false)
    {
        
        if (personGender == "female" || personGender == "f") {
            contribution.setBonusStrategy(make_unique<FemaleBonusStrategy>());
        }
        else {
            contribution.setBonusStrategy(make_unique<MaleBonusStrategy>());
        }

        
        contribution.applyOpeningBonus();
    }

    Depositor(const Person& person)
        : Person(person.getName(), person.getAge(), person.getGender()), hasInteracted(false)
    {
        
        if (person.getGender() == "female" || person.getGender() == "f") {
            contribution.setBonusStrategy(make_unique<FemaleBonusStrategy>());
        }
        else {
            contribution.setBonusStrategy(make_unique<MaleBonusStrategy>());
        }

        
        contribution.applyOpeningBonus();
    }

    Contribution& getContribution() { return contribution; }

    
    virtual bool interact() override {
        //cout << "\n=== Взаимодействие с вкладчиком " << getName() << " ===" << endl;

        if (!hasInteracted) {
            cout << "Поздравляем с открытием вклада!" << endl;
            cout << "Текущий баланс: " << fixed << setprecision(2) << contribution.getSize() << " руб." << endl;
            cout << "Хочешь пополнить вклад? (1 - да, 0 - нет): ";

            int choice;
            while (true) {
                cin >> choice;
                if (isInt(choice) && (choice == 0 || choice == 1)) {
                    break;
                }
                cout << "Пожалуйста, введите 1 (да) или 0 (нет): ";
            }

            if (choice == 1) {
                double amount;
                cout << "Введите сумму для пополнения: ";
                while (true) {
                    cin >> amount;
                    if (isDouble(amount) && amount > 0) {
                        break;
                    }
                    cout << "Пожалуйста, введите положительное число: ";
                }
                makeDeposit(amount);
            }
            else {
                cout << "Хорошо, может быть в другой раз!" << endl;
            }
            hasInteracted = true;
        }
        else {
            cout << "Текущий баланс: " << fixed << setprecision(2) << contribution.getSize() << " руб." << endl;
            cout << "Хочешь пополнить вклад? (1 - да, 0 - нет): ";

            int choice;
            while (true) {
                cin >> choice;
                if (isInt(choice) && (choice == 0 || choice == 1)) {
                    break;
                }
                cout << "Пожалуйста, введите 1 (да) или 0 (нет): ";
            }

            if (choice == 1) {
                double amount;
                cout << "Введите сумму для пополнения: ";
                while (true) {
                    cin >> amount;
                    if (isDouble(amount) && amount > 0) {
                        break;
                    }
                    cout << "Пожалуйста, введите положительное число: ";
                }
                makeDeposit(amount);
            }
        }
        return true; 
    }

    virtual void display1() const override {
        cout << "Depositor: " << getName() << ", Age: " << getAge() << ", Gender: " << getGender() << endl;
        contribution.displayContribution();
    }

    void makeDeposit(double size) {
        contribution.addToContribution(size);
    }
};

class Bank
{
private:
    vector<unique_ptr<Person>> people;

public:
    void createPerson(const string& name, int age, const string& gender) {
        auto person = make_unique<Person>(name, age, gender);
        cout << "Создан человек: " << name << endl;

        
        bool wantsToBeDepositor = person->interact();

        if (wantsToBeDepositor) {
            
            auto depositor = make_unique<Depositor>(*person);
            people.push_back(move(depositor));
            cout << "Человек успешно стал вкладчиком!" << endl;
        }
        else {
            
            people.push_back(move(person));
        }
    }

    void makePersonDepositor(int index) {
        if (index < 0 || index >= people.size()) {
            cout << "Неверный индекс!" << endl;
            return;
        }

        
        if (dynamic_cast<Depositor*>(people[index].get())) {
            cout << "Этот человек уже вкладчик!" << endl;
            return;
        }

        
        auto depositor = make_unique<Depositor>(*people[index]);

        
        people[index] = move(depositor);
        cout << "Человек теперь вкладчик!" << endl;

        
        people[index]->interact();
    }

    void addToDeposit(int index, double amount) {
        if (index < 0 || index >= people.size()) {
            cout << "Неверный индекс!" << endl;
            return;
        }

        Depositor* depositor = dynamic_cast<Depositor*>(people[index].get());
        if (depositor) {
            depositor->makeDeposit(amount);
        }
        else {
            cout << "Этот человек еще не вкладчик!" << endl;
        }
    }

    void displayAll() const {
        if (people.empty()) {
            cout << "Нет людей в системе." << endl;
            return;
        }

        for (size_t i = 0; i < people.size(); ++i) {
            cout << i << ": ";
            people[i]->display1();
            cout << "---" << endl;
        }
    }

    double getTotalDeposits() const {
        double total = 0.0;

        for (const auto& person : people) {
            Depositor* depositor = dynamic_cast<Depositor*>(person.get());
            if (depositor) {
                total += depositor->getContribution().getSize();
            }
        }

        return total;
    }

    void showDepositsStatistics() const {
        double total = getTotalDeposits();
        int depositorCount = 0;
        int personCount = 0;

        for (const auto& person : people) {
            if (dynamic_cast<Depositor*>(person.get())) {
                depositorCount++;
            }
            else {
                personCount++;
            }
        }

        cout << "\n=== СТАТИСТИКА БАНКА ===" << endl;
        cout << "Общее количество людей: " << people.size() << endl;
        cout << "Обычных людей: " << personCount << endl;
        cout << "Вкладчиков: " << depositorCount << endl;
        cout << "Общая сумма всех вкладов: " << fixed << setprecision(2) << total << " руб." << endl;
        cout << "Средний вклад: " << fixed << setprecision(2) << (depositorCount > 0 ? total / depositorCount : 0) << " руб." << endl;
    }

    bool isDepositor(int index) const {
        return dynamic_cast<Depositor*>(people[index].get()) != nullptr;
    }

    size_t getPeopleCount() const { return people.size(); }
};

void runMenu() {
    Bank bank;
    int choice;

    do {
        while (true) {
            cout << "\n=== БАНКОВСКАЯ СИСТЕМА ===" << endl;
            cout << "1. Создать человека" << endl;
            cout << "2. Сделать человека вкладчиком" << endl;
            cout << "3. Пополнить вклад" << endl;
            cout << "4. Показать всех" << endl;
            cout << "5. Общая сумма вкладов" << endl;
            cout << "6. Выход" << endl;
            cout << "Выбор: ";
            cin >> choice;
            if (isInt(choice) && choice > 0 && choice < 7) {
                break;
            }
            else {
                cout << "Неверный выбор! Введите число от 1 до 6." << endl;
            }
        }

        switch (choice) {
        case 1: {
            string name, gender;
            int age;

            cout << "Имя: ";
            cin >> name;

            while (true) {
                cout << "Пол (m/f): ";
                cin >> gender;
                if (gender == "m" || gender == "f" || gender == "M" || gender == "F") {
                    // Приводим к нижнему регистру для единообразия
                    if (gender == "M") gender = "m";
                    if (gender == "F") gender = "f";
                    break;
                }
                else {
                    cout << "Ошибка: пол должен быть 'm' или 'f'!" << endl;
                }
            }


            while (true) {
                cout << "Возраст: ";
                cin >> age;
                if (isInt(age) && age >= 18) {
                    break;
                }
                else {
                    cout << "Ошибка: возраст должен быть числом и не менее 18 лет!" << endl;
                }
            }
            bank.createPerson(name, age, gender);
            break;
        }
        case 2: {
            if (bank.getPeopleCount() == 0) {
                cout << "Нет людей в системе!" << endl;
                break;
            }

            int index;
            while (true) {
                cout << "Индекс человека (0-" << bank.getPeopleCount() - 1 << "): ";
                cin >> index;
                if (isInt(index) && index >= 0 && index < bank.getPeopleCount()) {
                    if (!bank.isDepositor(index)) {
                        bank.makePersonDepositor(index);
                        break;  
                    }
                    else {
                        cout << "Этот человек уже вкладчик! Возврат в меню." << endl;
                        break;  
                    }
                }
                else {
                    cout << "Неверный индекс!" << endl;
                }
            }
            break; 
        }
        case 3: {
    if (bank.getPeopleCount() == 0) {
        cout << "Нет людей в системе!" << endl;
        break;
    }

    int index;
    double amount;

    while (true) {
        cout << "Индекс вкладчика (0-" << bank.getPeopleCount() - 1 << "): ";
        cin >> index;

        if (isInt(index) && index >= 0 && index < bank.getPeopleCount()) {
            if (bank.isDepositor(index)) {
                break;
            }
            else {
                cout << "Этот человек не вкладчик! Нажмите 0 для выхода или 1 для продолжения: ";
                int exitChoice;
                cin >> exitChoice;
                if (exitChoice == 0) {
                    break; // ИЗМЕНИЛ return на break - выходим из цикла в меню
                }
                // если 1 - продолжаем циклkswd
            }
        }
        else {
            cout << "Неверный индекс!" << endl;
        }
    }

    // Проверяем, нашли ли мы вкладчика
    if (index >= 0 && index < bank.getPeopleCount() && bank.isDepositor(index)) {
        while (true) {
            cout << "Сумма: ";
            cin >> amount;
            if (isDouble(amount) && amount > 0 && amount < 9999999999991
        ) {
                bank.addToDeposit(index, amount);
                break;
            }
            else {
                cout << "Сумма должна быть положительным числом!" << endl;
            }
        }
    }
    break;
}
        case 4:
            bank.displayAll();
            break;
        case 5:
            bank.showDepositsStatistics();
            break;
        case 6:
            cout << "Выход из программы..." << endl;
            break;
        }
    } while (choice != 6);
}

int main()
{
    setlocale(LC_ALL, "RU");
    
    cout << fixed << setprecision(2);
    runMenu();
    return 0;
}
