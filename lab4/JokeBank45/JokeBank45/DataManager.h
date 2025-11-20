#pragma once

#include <msclr/marshal_cppstd.h>

namespace JokeBank45 {

    using namespace System;
    using namespace System::Collections::Generic;

    public ref class ManagedContributor
    {
    private:
        String^ _name;
        int _age;
        double _size;

    public:
        property String^ Name {
            String^ get() { return _name; }
            void set(String^ value) { _name = value; }
        }

        property int Age {
            int get() { return _age; }
            void set(int value) { _age = value; }
        }

        property double Size {
            double get() { return _size; }
            void set(double value) { _size = value; }
        }

        ManagedContributor(String^ name, int age)
        {
            _name = name;
            _age = age;
            _size = 0.0;
        }
    };

    public ref class DataManager sealed
    {
    private:
        static DataManager^ _instance = nullptr;
        List<ManagedContributor^>^ contributors;

        DataManager()
        {
            contributors = gcnew List<ManagedContributor^>();
        }

    public:
        static property DataManager^ Instance
        {
            DataManager^ get()
            {
                if (_instance == nullptr)
                {
                    _instance = gcnew DataManager();
                }
                return _instance;
            }
        }

        // Добавить Contributor
        void AddContributor(String^ name, int age)
        {
            ManagedContributor^ newContributor = gcnew ManagedContributor(name, age);
            contributors->Add(newContributor);
        }

        // Получить Contributor по индексу
        ManagedContributor^ GetContributor(int index)
        {
            if (index >= 0 && index < contributors->Count)
                return contributors[index];
            return nullptr;
        }

        // Получить количество Contributors
        int GetContributorCount()
        {
            return contributors->Count;
        }

        // Найти Contributor по имени
        ManagedContributor^ FindContributorByName(String^ name)
        {
            for each (ManagedContributor ^ contributor in contributors)
            {
                if (contributor->Name->Equals(name))
                    return contributor;
            }
            return nullptr;
        }

        // Получить всех Contributors
        List<ManagedContributor^>^ GetAllContributors()
        {
            return contributors;
        }

        // Удалить Contributor по индексу
        bool RemoveContributor(int index)
        {
            if (index >= 0 && index < contributors->Count)
            {
                contributors->RemoveAt(index);
                return true;
            }
            return false;
        }

        // Удалить Contributor по имени
        bool RemoveContributorByName(String^ name)
        {
            for (int i = 0; i < contributors->Count; i++)
            {
                if (contributors[i]->Name->Equals(name))
                {
                    contributors->RemoveAt(i);
                    return true;
                }
            }
            return false;
        }

        // Обновить Contributor
        bool UpdateContributor(int index, String^ name, int age, double size)
        {
            if (index >= 0 && index < contributors->Count)
            {
                contributors[index]->Name = name;
                contributors[index]->Age = age;
                contributors[index]->Size = size;
                return true;
            }
            return false;
        }
    };
}