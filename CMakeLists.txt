cmake_minimum_required(VERSION 3.26)
project(Project_Chicago C)

set(CMAKE_C_STANDARD 11)

add_executable(Project_Chicago main.c
        add_quote.h
        add_quote.c
        struct.h
        edit_quote.h
        edit_quote.c
        display_quote.c
        display_quote.h
        delete_quote.c
        delete_quote.h
        read_quotes.c
        read_quotes.h)
