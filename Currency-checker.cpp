#include "Currency-checker.h"
using json = nlohmann::json;
template<typename T>
void input_validator(short& choice ,short min, short max, T function);
void loading_program();
void make_another_operation(char& var);

//CHOICE OPTIONS - BEGIN
void choice_options();
void choice();
void currency_options();
void pick_currency_today();
void pick_currency_last_busisnes();
void pick_currency_on_specific_day();
void save_to_file(const std::string& json_dump);
void print_json_from_api(const std::string& json_dump);
//CHOICE OPTIONS - END

std::string get_api_query_today(const std::string& currency);
std::string get_api_query_with_specific_date(const std::string& currency, const std::string& date);

int main()
{
    loading_program();
    std::cout << "Loading program...";
    Sleep(2500);
    choice();

    return 0;
}

void loading_program()
{
    std::cout << "|---------------------------------|\n";
    std::cout << "|---------Currency checker--------|\n";
    std::cout << "|-----Made by Szymon Chirowski----|\n";
    std::cout << "|---(C)2022 All rights reserved---|\n";
    std::cout << "|---------------------------------|\n";
}

void make_another_operation(char& var)
{
    std::cout << "Do you want to make another operation? Y/N\n";;
    std::cin >> var;
    var = toupper(var);
    if (var != 'Y')
    {
        var = 'N';
    }
}

void choice_options()
{
    std::cout << "1. Check today's currency rate.\n";
    std::cout << "2. Check the exchange rate of a specific day.\n";
    std::cout << "3. Check the previous business day's currency price.\n";
    std::cout << "4. Exit.\n";
}

void choice()
{
    short choice;
    char do_another_operation = 'N';

    do
    {
        system("cls");
        choice_options();
        std::cin >> choice;
        input_validator(choice, 1, 4, choice_options);

        switch (choice)
        {
            case 1:
                pick_currency_today();
                break;
            case 2:
                pick_currency_on_specific_day();
                break;
            case 3:
                pick_currency_last_busisnes();
                break;
            case 4:
                system("cls");
                do_another_operation = 'N';
                break;
            default:
                system("cls");
                std::cout << "Restart the program.\n";
                break;
        }
        if (choice != 4)
        {
            make_another_operation(do_another_operation);
        }
    } while (do_another_operation == 'Y');
}

void currency_options()
{
    std::cout << "1. EUR\n";
    std::cout << "2. USD\n";
    std::cout << "3. CHF\n";
    std::cout << "4. GBP\n";
}

void pick_currency_today()
{
    short choice;
    char do_another_operation = 'N';
    std::string currency, json_dump;

    Date_time time;

    if (time.get_hour() <= 10)
    {
        std::cout << "Sorry, but it's too early, please try again later.\n";
        return;
    }

    do
    {
        system("cls");
        currency_options();
        std::cin >> choice;
        input_validator(choice, 1, 4, currency_options);
        
        switch (choice)
        {
            case 1:
                currency = "eur";
                json_dump = get_api_query_today(currency);
                break;
            case 2:
                currency = "usd";
                json_dump = get_api_query_today(currency);
                break;
            case 3:
                currency = "chf";
                json_dump = get_api_query_today(currency);
                break;
            case 4:
                currency = "gbp";
                json_dump = get_api_query_today(currency);
                break;
            default:
                system("cls");
                std::cout << "Restart the program.\n";
                break;
        }
        print_json_from_api(json_dump);

        save_to_file(json_dump);

        make_another_operation(do_another_operation);

    } while (do_another_operation == 'Y');
}

void pick_currency_last_busisnes()
{
    short choice;
    char do_another_operation = 'N';
    std::string currency, json_dump;

    Date_time time;

    time.set_date_to_last_busisnes_day();

    do
    {
        system("cls");
        currency_options();
        std::cin >> choice;
        input_validator(choice, 1, 4, currency_options);

        switch (choice)
        {
            case 1:
                currency = "eur";
                json_dump = get_api_query_with_specific_date(currency, time.make_date_to_url());
                break;
            case 2:
                currency = "usd";
                json_dump = get_api_query_with_specific_date(currency, time.make_date_to_url());
                break;
            case 3:
                currency = "chf";
                json_dump = get_api_query_with_specific_date(currency, time.make_date_to_url());
                break;
            case 4:
                currency = "gbp";
                json_dump = get_api_query_with_specific_date(currency, time.make_date_to_url());
                break;
            default:
                system("cls");
                std::cout << "Restart the program.\n";
                break;
        }
        print_json_from_api(json_dump);

        save_to_file(json_dump);

        make_another_operation(do_another_operation);

    } while (do_another_operation == 'Y');
}

void pick_currency_on_specific_day()
{
    short choice;
    char do_another_operation = 'N', is_data_ok = 'N';
    std::string currency, json_dump;
    int year = 0, month = 0, day = 0;

    Date_time time;

    do
    {
        do
        {
            system("cls");
            std::cout << "Set year.\n";
            std::cin >> year;
            std::cout << "Set month.\n";
            std::cin >> month;
            std::cout << "Set day.\n";
            std::cin >> day;

            if (!time.validate_date(year, month, day))
            {
                system("cls");
                std::cout << "Your date is from future, please set up your date once again.\n";
                is_data_ok = 'N';
            }
            else
            {
                system("cls");
                std::cout << "Is your data ok? Y/N\nDate: " << year << "-" << month << "-" << day <<"\n";
                std::cin >> is_data_ok;
                is_data_ok = toupper(is_data_ok);
                time.set_year(year);
                time.set_month(month);
                time.set_day(day);
            }
            

        } while (is_data_ok != 'Y');
        system("cls");
        currency_options();
        std::cin >> choice;
        input_validator(choice, 1, 4, currency_options);

        switch (choice)
        {
            case 1:
                currency = "eur";
                json_dump = get_api_query_with_specific_date(currency, time.make_date_to_url());
                break;
            case 2:
                currency = "usd";
                json_dump = get_api_query_with_specific_date(currency, time.make_date_to_url());
                break;
            case 3:
                currency = "chf";
                json_dump = get_api_query_with_specific_date(currency, time.make_date_to_url());
                break;
            case 4:
                currency = "gbp";
                json_dump = get_api_query_with_specific_date(currency, time.make_date_to_url());
                break;
            default:
                system("cls");
                std::cout << "Restart the program.\n";
                break;
        }
        print_json_from_api(json_dump);

        save_to_file(json_dump);

        make_another_operation(do_another_operation);

    } while (do_another_operation == 'Y');
}

void save_to_file(const std::string& json_dump)
{
    char save_to_file = 'N';
    File o;
    Date_time time;
    std::cout << "Do you wanna save this to file? Y/N\n";
    std::cin >> save_to_file;
    save_to_file = toupper(save_to_file);
    if (save_to_file == 'Y')
    {
        o.save_json_to_file(json_dump, time.make_date_to_url());
    }
}

void print_json_from_api(const std::string& json_dump)
{
    auto output = json::parse(json_dump);
    std::cout << output.dump(4) << "\n";
}

std::string get_api_query_today(const std::string& currency)
{
    std::string api_result;

    HTTP_con_handler handler;
    handler.set_currency(currency);
    handler.make_GET_request_today();
    api_result = handler.get_text();
    return api_result;
}

std::string get_api_query_with_specific_date(const std::string& currency, const std::string& date)
{
    std::string api_result;

    HTTP_con_handler handler;
    handler.set_currency(currency);
    handler.make_GET_request_with_date(date);
    api_result = handler.get_text();
    return api_result;
}

template<typename T>
void input_validator(short& choice, short min, short max, T function)
{
    while ((choice < min) || (choice > max))
    {
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        system("cls");
        
        function();

        std::cout << "You picked wrong option pick option once again.\n";
        std::cin >> choice;
    }
}
