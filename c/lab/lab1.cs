using System;

namespace lab1
{
    public class Programs
    {
      
        private static string channel;
        protected string name; // доступ внутри класса и производных экземпляров классов 
        public virtual string Name // можно переопределить Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }
        public Programs() { }  // публічний конструктор
       
        public Programs(string name)
        {
            this.Name = Name;
        }
        static Programs()
        {
            channel = "LostFilm";
        }
        public static void ShowChannel()
        {
            Console.WriteLine("All programs are shown by {0}", channel);
        }
        /*public void ShowName()
        {
            Console.WriteLine("Name : {0}", Name);
        }   
        */
        public virtual void Print()
        {
            Console.WriteLine("Name : {0}", Name);

        }
    }

    public class Adult_Only 
    {
        string name;
        static string  pass = "password";

        private Adult_Only(string name)
        {
            this.name = name;   
        }
        public static Adult_Only download(string password, int code)
        {
            if (pass == password)
            {
                switch (code)
                {
                    case 04:
                        return new Adult_Only("qwertt");
                        
                    case 075:
                        return new Adult_Only("asd");
                    default:
                        Console.Write("Wrong coede, no such film");
                        break;
                }
            }
            return null;
        }
     
    }
    public class Characteristic : Programs
    {
        protected int year; // доступ внутри класса и производных экземпляров классов 
        protected double duration;
        protected string ageRestriction;
        protected string country;
        protected bool popularity;

        public override string Name // override - переопределение Name
        {
            get
            {
                return name;
            }
            set
            {
                if (value != String.Empty)
                {
                    name = value;
                }
                else
                {
                    name = "Unknown";
                }
            }
        }
        public Characteristic() // конструктор за замовчуванням
        {
            popularity = true;
        }
        public Characteristic(string name, int year, string country, bool popularity, double duration, string ageRestriction) // перевизначений конструктор 
            : base(name)
        {
            this.name = name;
            this.ageRestriction = ageRestriction;
            this.duration = duration;
            this.year = year;
            this.country = country;
            this.popularity = popularity;
        }
        public void Info()
        {
            Console.WriteLine("Name:{0}", name);
            Console.WriteLine("Duration: {0} ", duration);
            Console.WriteLine("Year: {0}", year);
            Console.WriteLine("Country: {0}", country);
            Console.WriteLine("Age restriction: {0}", ageRestriction);
            Console.WriteLine("Popularity: {0}", popularity);
        }
      /*  public override  void Print1()
        {
            base.Print();
            Console.WriteLine("Duration: {0} ", duration);
            Console.WriteLine("Year: {0}", year);
            Console.WriteLine("Country: {0}", country);
            Console.WriteLine("Age restriction: {0}", ageRestriction);
            Console.WriteLiene("Popularity: {0}", popularity);
        }*/
        public override void Print()
        {
            base.Print();
            Console.WriteLine("Year: {0}", year);
            Console.WriteLine("Country: {0}", country);
            Console.WriteLine("Age restriction: {0}", ageRestriction);
            Console.WriteLine("Popularity: {0}", popularity);

        }
    }

    public class Serial : Characteristic
    {
        private string type;
        protected int seasons; // доступ внутри класса и производных экземпляров классов 
        protected int series;

        public Serial(string name, int year, string country, bool popularity, float duration, int seasons, int series, string ageRestriction) // перевизначений конструктор 
            : base(name, year, country, popularity, duration, ageRestriction)
        {
            this.seasons = seasons;
            this.series = series;
        }
       /* public void Print()
        {
            Console.WriteLine("Name {0}", name);
            Console.WriteLine("year {0}", year);
            Console.WriteLine("country {0}", country);
            Console.WriteLine("popularity {0}", popularity);
            Console.WriteLine("duration {0}", duration);
            Console.WriteLine("seasons {0}", seasons);
            Console.WriteLine("series {0}", series);
            Console.WriteLine("ageRestriction {0}", ageRestriction);
            Console.WriteLine("Type:{0}", type);
        }*/
        public Serial() // конструктор за замовчуванням
        {
            type = "Serial";
        }
       /* public override  void  Show()
        {
            Info();
            Console.WriteLine("Seasons: {0}", seasons);
            Console.WriteLine("Series: {0}", series);
            Console.WriteLine("Type: {0}", type);
        }
        **/
        public override void Print(){
            base.Print();
            Console.WriteLine("Year: {0}", year);
            Console.WriteLine("Country: {0}", country);
            Console.WriteLine("Age restriction: {0}", ageRestriction);
            Console.WriteLine("Popularity: {0}", popularity);
            Console.WriteLine("Seasons: {0}", seasons);
            Console.WriteLine("Series: {0}", series);
            Console.WriteLine("Type: {0}", type);
        }
    }
    public class Film : Characteristic
    {
        private string type;
        protected int part; // доступ внутри класса и производных экземпляров классов 

        public Film(string name, int year, string country, bool popularity, float duration, string ageRestriction, int part) // перевизначений конструктор 
            : base(name, year, country, popularity, duration, ageRestriction)
        {
            this.part = part;
        }
        public Film() // конструктор за замовчуванням 
        {
            type = "Film";
        }
      /*  public void Show()
        {
            Info();

            Console.WriteLine("Part: {0}", part);
            Console.WriteLine("Type: {0}", type);
        }*/
        public override void Print()
{
 	 base.Print();
            Console.WriteLine("Year: {0}", year);
            Console.WriteLine("Country: {0}", country);
            Console.WriteLine("Age restriction: {0}", ageRestriction);
            Console.WriteLine("Popularity: {0}", popularity);
           // Console.WriteLine("Seasons: {0}", seasons);
           // Console.WriteLine("Series: {0}", series);
            Console.WriteLine("Type: {0}", type);
             Console.WriteLine("Part: {0}", part);

}
    }

    sealed public class Show_Serial : Serial // никакие классы не могут наследовать от класса Show_Serial
    {
        public Show_Serial() // статичний конструктор
        {
            Name = "Mr. Robot";
            seasons = 1;
            series = 10;
            duration = 58.45;
            year = 2015;
            country = "USA";
            ageRestriction = "16+";
            popularity = false;
        }


    }
    sealed public class Show_Film : Film
    {
        public Show_Film()
        {
            Name = "Star Wars";
            part = 4;
            duration = 02.01;
            year = 1977;
            country = "USA";
            ageRestriction = "0+";

        }
    }



    class Program
    {
        static void Main(string[] args)
        {
            Adult_Only adult = Adult_Only.download("password", 074);
            
            Programs.ShowChannel();

            Console.WriteLine();
            Show_Serial first = new Show_Serial();
            first.Print();
            Console.WriteLine();
            Show_Film second = new Show_Film();
            second.Print();
            Console.WriteLine();
            Console.WriteLine();
            Characteristic fourth = new Characteristic("Now you see me", 2001, "usa", false, 2.4, "6+");
            fourth.Info();
            Console.ReadKey();
            //string name, int year, string country, bool popularity, float duration, int seasons, int series, string ageRestriction
            // string name, int year, string country, bool popularity, float duration, string ageRestriction
        }
    }
}
