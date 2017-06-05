using System;

namespace LR5
{

    class Program
    {
        static void Main(string[] args)
        {

            while (true)
            {
                menu();

                switch (intCheck())
                {
                    case 1:
                        analysis();
                        break;
                    case 2:
                    default:
                        return;
                }
                Console.ReadKey();
                Console.Clear();
            }

        }

        static public void menu()
        {
            Console.WriteLine("Меню:");
            Console.WriteLine("1. Добавить нового пользователя");
            Console.WriteLine("2. Выход");
            Console.WriteLine("Введите номер нужного действия : ");
        }
        static public void analysis()
        {
            string name;
            Console.Write("Ваше имя : ");
            name = Console.ReadLine();
            Console.WriteLine("Являетесь ли вы спортсменом? (да/нет)");
            string answer = Console.ReadLine();
            while (answer != "да" && answer != "нет")
            {
                Console.WriteLine("Ошибка ввода! Попробуйте снова : ");
                answer = Console.ReadLine();
            }

            if (answer == "да")
            {
                Console.WriteLine("Введите через enter ваш рост, вес, возраст, пол (м/ж)");
                double height = doubleCheck();
                double weight = doubleCheck();
                int age = intCheck();
                string gender = Console.ReadLine();
                while (gender != "ж" && gender != "м")
                {
                    Console.WriteLine("Ошибка ввода! Попробуйте снова : ");
                    gender = Console.ReadLine();
                }

                Console.WriteLine("Являетесь ли вы профессиональным спортсменом ? (да/нет)");
                answer = Console.ReadLine();
                while (answer != "да" && answer != "нет")
                {
                    Console.WriteLine("Ошибка ввода! Попробуйте снова : ");
                    answer = Console.ReadLine();
                }

                if (answer == "да")
                {
                    Console.Write("Количество тренировок в неделю : ");
                    int number = intCheck();
                    Console.Write("Процент мышц в теле : ");
                    int muscles = intCheck();
                    Profi person = new Profi(name, height, weight, age, gender, number, muscles);
                    person.Report(name);
                }
                else
                {
                    Sportsman person = new Sportsman(name, height, weight, age, gender);
                    person.Report(name);
                }

            }
            else
            {
                Human person = new Human(name);
                person.Report(name);
            }
        }

        public static double doubleCheck()
        {
            while (true)
            {
                double i;
                if (double.TryParse(Console.ReadLine(), out i))
                    return i;
                else
                    Console.Write("Ошибка ввода! Введите еще раз: ");
            }
        }

        public static int intCheck()
        {
            while (true)
            {
                int i;
                if (int.TryParse(Console.ReadLine(), out i))
                    return i;
                else
                    Console.Write("Ошибка ввода! Введите еще раз: ");
            }
        }

    }

    public class Human
    {
        string Name;

        public Human()
        {
        }


        public Human(string name)
        {
            Name = name;
        }

        public string name
        {
            get { return Name; }
            set { Name = value; }
        }

        public void Report(string name)
        {
            Console.WriteLine("{0} не является спортсменом. Дальнейший анализ показателей невозможен", name);
        }
    }

    interface IFace
    {
        //double  basicMeta();
        void Report(string name);
    }

    public class Sportsman : Human, IFace
    {
        private double Height;
        private double Weight;
        private int Age;
        private string Gender;

        public Sportsman()
        {
        }

        public Sportsman(string Name, double height, double weight, int age, string gender)
            : base(Name)
        {
            Height = height;
            Weight = weight;
            Age = age;
            Gender = gender;
        }

        public delegate double Del();

        public double height
        {
            get { return Height; }
            set { Height = value; }
        }

        public double weight
        {
            get { return Weight; }
            set { Height = value; }
        }

        public int age
        {
            get { return Age; }
            set { Age = value; }
        }

        public string gender
        {
            get { return Gender; }
            set { Gender = value; }
        }

        public void Report(string name)
        {
            Console.WriteLine("Имя :\t\t\t" + name);
            Console.WriteLine("Рост :\t\t\t" + height);
            Console.WriteLine("Вес :\t\t\t" + weight);
            Console.WriteLine("Возраст :\t\t" + age);
            Console.WriteLine("Пол :\t\t\t" + gender);
            BMI();
            Del q = basicMeta;
            Console.WriteLine("Метаболизм :\t\t" + q());
            q = waterBalance;
            Console.WriteLine("Потребность воды :\t" + q());
        }
          
        public double basicMeta()
        {
            double meta = 0;
            if (gender == "м")
                meta = 66 + (13.7 * weight) + (5 * height * 100) - (6.8 * age);
            else if (gender == "ж")
                meta = 655 + (9.6 * weight) + (1.8 * height * 100) - (4.7 * age);
            return meta;
        }

        public double waterBalance()
        {
            double water = 0;
            if (gender == "м")
                water = weight * 35;
            else if (gender == "ж")
                water = weight * 31;
            return water;
        }

        enum bmi { Острый_дефицит, Дефицит, Норма, Перебор, Избыток }

        public void BMI()
        {
            double BMI = weight / Math.Pow(height, 2);

            Console.Write("Ваш BMI составляет :\t" + "{0:0.00}. ", BMI);
            if (BMI <= 15)
                Console.WriteLine(bmi.Острый_дефицит);
            else if (BMI > 15 && BMI <= 20)
                Console.WriteLine(bmi.Дефицит);
            else if (BMI > 20 && BMI <= 25)
                Console.WriteLine(bmi.Норма);
            else if (BMI > 25 && BMI <= 30)
                Console.WriteLine(bmi.Перебор);
            else if (BMI > 30)
                Console.WriteLine(bmi.Избыток);
        }

    }
    public delegate double Del();
    public class Profi : Sportsman, IFace
    {
        private int Muscles;
        private int Number;

        public Profi(string Name, double height, double weight, int age, string gender, int number, int muscles)
            : base(Name, height, weight, age, gender)
        {
            Muscles = muscles;
            Number = number;
        }

        public int muscles
        {
            get { return Muscles; }
            set { Muscles = value; }
        }

        public int number
        {
            get { return Number; }
            set { Number = value; }
        }
        
        
        public double basicMeta()
        {
            double meta = 0;
            if (gender == "м")
                meta = 66 + (13.7 * weight) + (5 * height * 100) - (6.8 * age);
            else if (gender == "ж")
                meta = 655 + (9.6 * weight) + (1.8 * height * 100) - (4.7 * age);


            if (number <= 3) meta *= 1.275;
            else if (number <= 5) meta *= 1.55;
            else if (number <= 7) meta *= 1.725;
            else if (number <= 14) meta *= 1.9;

            return meta;
        }

        enum form { Недостаток, Много, Перфект }
        public void musclesAnalyses(int muscles, string gender)
        {
            Console.Write("Процент мышц : \t\t" + muscles + "\t");
            if (gender == "ж")
            {
                if (muscles < 33)
                    Console.WriteLine(form.Недостаток);
                else if (muscles > 39)
                    Console.WriteLine(form.Много);
                else
                    Console.WriteLine(form.Перфект);
            }

            else if (gender == "м")
            {
                if (muscles < 41)
                    Console.WriteLine(form.Недостаток);
                else if (muscles > 52)
                    Console.WriteLine(form.Много);
                else
                    Console.WriteLine(form.Перфект);
            }
        }

        public void Report(string name)
        {
            Console.WriteLine("Имя :\t\t\t" + name);
            Console.WriteLine("Рост :\t\t\t" + height);
            Console.WriteLine("Вес :\t\t\t" + weight);
            Console.WriteLine("Возраст :\t\t" + age);
            Console.WriteLine("Пол :\t\t\t" + gender);
            BMI();
            Del q = basicMeta;
            Console.WriteLine("Метаболизм :\t\t" + q());
            q = waterBalance;
            Console.WriteLine("Потребность воды :\t" + q());
        }

    }
}
