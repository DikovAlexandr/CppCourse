#include <iostream>
#include <string>
#include <vector>
#include <map>
// Программа рекомменндующая фильм, звезду и песню при регистрации
using namespace std;
// Функция получения номера фильма
int getmovie(string s) {
    return int(s[0]);
}
// Функция получения номера звезды
int getvip(string s) {
    return int(s[0]);
}
// Функция нахождения суммы цифр числа
int sum(int x) {
    int y = 0;
    while (x != 0) {
        y += x % 10;
        x /= 10;
    }
    return y;
}
// Фунция получения номера песни
int getmusic(int a, int b, int c) {
    int num = sum(a) + sum(b) + sum(c);
    if (sum(num) >= 10) return sum(sum(num));
    else return sum(num);
}
// Объявление структуры пользователя
struct person {
    int day = 0, month = 0, year = 0;
    string name, surname;
};
// Тело функции
int main() {
    person human;
    string s, d;
    int c = 0;
    bool f = false;
    // Считывание имени и фамилии
    cout << "Hey, we have some fun content for you. Enter yor name and surname\n";
    getline(cin, s);
    for (char i: s)
        if (i != ' ') {
            if (!f) human.name += i;
            else human.surname += i;
        } else f = true;
    //cout << human.name << " " << human.surname << endl;
    // Считывание даты рождения
    cout << "Date of birth in the format dd.mm.yyyy\n";
    cin >> d;
    for (char i: d)
        if (i != '.') {
            if (c == 0) human.day = human.day * 10 + int(i) - 48;
            else if (c == 1) human.month = human.month * 10 + int(i) - 48;
            else human.year = human.year * 10 + int(i) - 48;
        } else c++;
    //cout << human.day << " " << human.month << " " << human.year << endl;
    // Создание таблицы фильмов
    map <int, string> movie;
    movie[0] = "Meet Joe Black";
    movie[1] = "The Lincoln Lawyer";
    movie[2] = "Blade Runner 2048";
    movie[3] = "Shutter Island";
    movie[4] = "Memento";
    movie[5] = "Fight club";
    movie[6] = "The Shawshank Redemption";
    movie[7] = "The Green Mile";
    movie[8] = "Forrest Gump";
    movie[9] = "The Prestige";
    movie[10] = "A Beautiful Mind";
    movie[11] = "Django Unchained";
    movie[12] = "One Flew Over the Cuckoo's Nest";
    movie[13] = "Leon";
    movie[14] = "The Platform";
    movie[15] = "The Godfather";
    movie[16] = "The Silence of the Lambs";
    movie[17] = "Don't Worry, He Won't Get Far on Foot";
    movie[18] = "The wolf of Wall Street";
    movie[19] = "Dallas Buyers Club";
    movie[20] = "Taxi driver";
    movie[21] = "Joker";
    movie[22] = "Drive";
    movie[23] = "Inglourious Basterds";
    movie[24] = "The Devil's Advocate";
    movie[25] = "Requiem for a Dream";
    // Создание таблицы звезд
    map <int, string> vip;
    vip[0] = "Robert Downey, Jr.";
    vip[1] = "Tom Cruise";
    vip[2] = "Tom Hanks";
    vip[3] = "James Franco";
    vip[4] = "Johnny Depp";
    vip[5] = "Emma Watson";
    vip[6] = "Will Smith";
    vip[7] = "Elizabeth Olsen";
    vip[8] = "Daniel Radcliffe";
    vip[9] = "Benedict Cumberbatch";
    vip[10] = "Harrison Ford";
    vip[11] = "Leonardo DiCaprio";
    vip[12] = "Tom Hiddleston";
    vip[13] = "Paul Bettany";
    vip[14] = "Brad Pitt";
    vip[15] = "Hugh Jackman";
    vip[16] = "Ian McKellen";
    vip[17] = "Gwyneth Paltrow";
    vip[18] = "Jennifer Lawrence";
    vip[19] = "Natalie Portman";
    vip[20] = "Christian Bale";
    vip[21] = "Robert De Niro";
    vip[22] = "Keanu Reeves";
    vip[23] = "Robert Pattinson";
    vip[24] = "Jude Law";
    vip[25] = "Russell Crowe";
    // Создание таблицы песен
    map <int, string> music;
    music[0] = "Machine Gun Kelly - papercuts";
    music[1] = "Thirty Seconds To Mars - A Beautiful Lie";
    music[2] = "Falling In Reverse - The Drug In Me Is Reimagined";
    music[3] = "David Bowie - Fame";
    music[4] = "Pierce The Veil - King for a Day ft. Kellin Quinn";
    music[5] = "Marilyn Manson - This Is The New Shit";
    music[6] = "Sting - Shape of My Heart";
    music[7] = "BAD OMENS - Never Know";
    music[8] = "Katy Perry - I Kissed A Girl";
    music[9] = "Lana Del Rey - High By The Beach";
    // Итоговый вывод рекоммендаций
    cout << "Super! Your movie for today is " << movie[getmovie(human.name)-65] << ", star"
                                                                                " " << vip[getvip(human.surname)-65] << ". Musical composition for "
                                                                                                                     "you: " << music[getmusic(human.day, human.month, human.year)] << endl;
    return 0;
}
