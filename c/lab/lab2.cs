using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab2
{
    public abstract class TV
    {
        protected static string channel;
        protected string name;
        public virtual string Name
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
        public TV() { }
        public TV(string name)
        {
            this.Name = Name;
        }
        static TV()
        {
            channel = "LostFilm";
        }
        public abstract void ShowChannel(); // абстрактный метод
        
        public void ShowName()
        {
            Console.WriteLine("Name : {0}", Name);
        }

    }

	 interface IProg
    {
        string WhatName();
        void ShowTitle();
    }
     interface IPlay
    {
        void Showplay();
        bool Playnow();

    }
	
    public abstract class Characteristic : TV
    {
        protected int year;
        protected double duration;
        protected string ageRestriction;
        private string title;
        protected string country;
        protected bool popularity;

       abstract public void SumTime(Summary c, SumEventArgs e);
        // abstract public void ShowChannel();

        public override string Name
        {
            get
            {
                return title;
            }
            set
            {
                if (value != String.Empty)
                {
                    title = value;
                }
                else
                {
                    title = "Unknown";
                }
            }
        }
        public Characteristic()
        {
            popularity = true;
        }
        public Characteristic(string name, int year, string country, bool popularity, float duration, string ageRestriction)
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
            ShowName();
            Console.WriteLine("Duration: {0}", duration);
            Console.WriteLine("Year: {0}", year);
            Console.WriteLine("Country: {0}", country);
            Console.WriteLine("Age restriction: {0}", ageRestriction);
            Console.WriteLine("Popularity: {0}", popularity);
        }
        public override void ShowChannel()
        {
            Console.WriteLine(Characteristic.channel);
        }
    }

    public class Ireviews<T>
    {
        public T rev;
		
     public Ireviews(T t){
           this.rev = t;
        }
     }

    public class Serial : Characteristic 
    {
        private string type;
        protected int seasons;
        protected int series;


        public Serial(string name, int year, string country, bool popularity, float duration, int seasons, int series, string ageRestriction)
            : base(name, year, country, popularity, duration, ageRestriction)
        {
            this.seasons = seasons;
            this.series = series;
        }
        public Serial()
        {
            type = "Serial";
        }
        public void ShowSerial()
        {
            Info();
            Console.WriteLine("Seasons: {0}", seasons);
            Console.WriteLine("Series: {0}", series);
            Console.WriteLine("Type: {0}", type);
        }
       /* public void Show_playnow()
        {
            Console.WriteLine("Does this show now?", Playnow());
        }*/
        public bool Playnow()
        {
           
            return true;
        }
       
        public override void ShowChannel()  // переопределение ShowChannel
        {
            Console.WriteLine("All programs are shown by {0}", channel);
        }
         public override void SumTime(Summary c, SumEventArgs e)
          {
              Console.WriteLine("{0} seasons of {3} on {1} channel take {2} minutes", e.amount_seasons, c.name, e.amount_seasons * this.duration, this.Name);
          }
        
    }

    public class Film : Characteristic
    {
        private string type;
        protected int part;
        public Film(string name, int year, string country, bool popularity, float duration, string ageRestriction, int part)
            : base(name, year, country, popularity, duration, ageRestriction)
        {
            this.part = part;
        }
        public Film()
        {
            type = "Film";
        }
        public void ShowFilm()
        {
            Info();
            Console.WriteLine("Part: {0}", part);
            Console.WriteLine("Type: {0}", type);
        }
        public override void ShowChannel()
        {
            Console.WriteLine("All programs are shown by {0}", channel);
        }
        public override void SumTime(Summary c, SumEventArgs e)
        {

            Console.WriteLine("{0} parts of {3} on {1} channel take {2} minutes", e.amount_parts, c.name, e.amount_parts * this.duration, this.Name);
        }
    }

    public sealed class Show_Serial : Serial // IProg, IEquatable<Show_Serial>
    {
        public Show_Serial()
        {
            Name = "Mr. Robot";
            seasons = 1;
            series = 10;
            duration = 49.54;
            year = 2015;
            country = "USA";
            ageRestriction = "16+";
            popularity = true;
        }
        public void SerialInfo()
        {
            ShowSerial();
        }
        public string WhatName()
        {
            return Name;
        }
        public void ShowTitle()
        {
            Console.WriteLine(" or you can watch '{0}'", WhatName());
        }
        public bool Equals(Show_Serial serial)
        {
            if (this.Name == serial.Name && this.seasons == serial.seasons)
                return true;
            else return false;
        }

    }
     
    public sealed class Show_Film : Film, IPlay , IProg //нельзя наследовать от Show_Film
    {
        public Show_Film()
        {
            Name = "Star Wars";
            part = 4;
            duration = 02.01;
            year = 1977;
            country = "USA";
            ageRestriction = "0+";
            popularity = true;
        }

        public void SerialInfo()
        {
            ShowFilm();
        }
        public string WhatName()
        {
            return Name;
        }
        public void ShowTitle()
        {
            Console.Write("You will watch '{0}'", WhatName());
        }
        public bool  Playnow()
        {
            return true;
        }
        public void Showplay()
        {
            Console.WriteLine("This is film translated");
        }
        public void fun()
        {
            if (Playnow() == true ){
                Showplay();
            }
        }
    }

   /* public enum MyExceptionArgs { FilmDoesNotExsist };

 
    public class NotFoundException : Exception // класс ошибки 
    {
        public NotFoundException()
        {

        }

        public NotFoundException(MyExceptionArgs arg, string message)
            : base(message)
        {
            Console.WriteLine("Error: " + arg.ToString());
        }

        public NotFoundException(string message, Exception inner)
            : base(message, inner)
        {
        }
    }
    class Producer
    {
        private string name;
        public Producer(string name)
        { 
            this.name = name;
        }
        public void filmed(ToProduce g)
        {
            Console.WriteLine(name + " filmed by " + g.Name);
        }
    }
    public delegate void story(ToProduce g);
    public class ToProduce
    {
        public event story toStory;
        private string name;
        public ToProduce(string name) { 
            this.name = name; 
        }
        public string Name
        {
            get {
                return name; 
            }
        }
        public void filmed()
        {
            if (toStory != null) toStory(this);
        }

    }
  */
   public delegate void Sumdel(Summary c, SumEventArgs e);
     public class Summary
     {
         public event Sumdel SumEvent;
         public string name;

         public Summary(string name)
         {
             this.name = name;
         }

         public void Sum()
         {
             SumEventArgs e;
             int count1, count2;
             count1 = 0;
             count2 = 0;
             try
             {
                 Console.Write("Enter how many seasons do you want to watch: ");
                 count1 = Int32.Parse(Console.ReadLine());
                 Console.Write("Enter how many parts do you want to watch: ");
                 count2 = Int32.Parse(Console.ReadLine());
                 e = new SumEventArgs(count1, count2);
               
             }
             catch (FormatException ex)
             {
               
                 Console.WriteLine("This is not number!\n");
                 Console.WriteLine("ОШИБКА: " + ex.Message + "\n\n");
                 Sum();
                 e = new SumEventArgs(1, 1);

               
             }
             if (SumEvent != null)
                 SumEvent((Summary)this, e);
            
         }
     }
   
    public class SumEventArgs : EventArgs
    {
        public int amount_seasons;
        public int amount_parts;
        public SumEventArgs(int amount_seasons, int amount_parts)
        {
            this.amount_seasons = amount_seasons;
            this.amount_parts = amount_parts;
        }
        SumEventArgs() : this(0, 0) { }
    }


    class Program
    {
        static void Main(string[] args)
        {
           /* Producer t1 = new Producer("Mr.Robot");
            Producer t2 = new Producer(" Star Wars");
            ToProduce g = new ToProduce("George Walton Lucas");
            g.toStory += t1.filmed;
            g.toStory += t2.filmed;
            g.filmed();
            */
          /*  Ireviews<int> b = new Ireviews<int>();
          
            Ireviews<int>.rev = 5;
            Console.WriteLine("Number of comments:", Ireviews<int>.rev);
            */

            string str = "Filmm is good";
            Ireviews<string> a = new Ireviews<string>(str);
            Console.WriteLine( a.rev);

            int number = 5;
            Ireviews<int> b = new Ireviews<int>(number);
            Console.WriteLine("Munber of comments:{0}" , b.rev);

            Show_Film film = new Show_Film();
            film.ShowTitle();
            Show_Serial serial = new Show_Serial();
            serial.ShowTitle();
            Show_Film ishow = new Show_Film();
            ishow.fun();

            Summary c = new Summary("MTV");
            Characteristic[] prog = new Characteristic[2];
            prog[0] = new Show_Serial();
            prog[1] = new Show_Film();

             foreach (Characteristic t in prog)
              {

                  c.SumEvent += new Sumdel(t.SumTime);
              }
              c.Sum();
            
            Console.WriteLine();
            Show_Serial first = new Show_Serial();
            first.ShowSerial();
            Console.WriteLine();
            Show_Film second = new Show_Film();
            second.ShowFilm();
            Console.ReadKey();

        }
    }
 }

 
