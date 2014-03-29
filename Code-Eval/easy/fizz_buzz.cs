using System.IO;

namespace FizzBuzz
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader reader = File.OpenText(args[0]))
                while (!reader.EndOfStream)
                {
                    string line = reader.ReadLine();
                    if (null == line)
                        continue;
                    else
                    {
                        string[] splitLine = line.Trim().Split(' ');
                        int m = int.Parse(splitLine[0]), n = int.Parse(splitLine[1]);
                        for (int i = 1; i <= int.Parse(splitLine[2]); i++)
                        {
                            if (i % m == 0 && i % n == 0) {
                                System.Console.Write("FB");
                            } else if (i % m == 0) {
                                System.Console.Write("F");
                            } else if (i % n == 0) {
                                System.Console.Write("B");
                            } else {
                                System.Console.Write(i);
                            }
                            System.Console.Write(" ");
                        }
                        System.Console.WriteLine();
                    }
                }
        }
    }
}
