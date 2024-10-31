/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

static const int EXPECTED_DIM_VALUE = 2;

static const char* CITY_NAMES[CITIES] = {
    "Cordoba", "Rosario", "Posadas", "Tilcara", "Bariloche"};
static const char* SEASON_NAMES[SEASONS] = {"low", "high"};

void array_dump(BakeryProductTable a)
{
    for (unsigned int city = 0u; city < CITIES; ++city)
    {
        for (unsigned int season = 0u; season < SEASONS; ++season)
        {
            fprintf(stdout, "%s in %s season: flour (%u,%u) Yeast (%u,%u) Butter (%u,%u) Sales value %u",
                    CITY_NAMES[city], SEASON_NAMES[season], a[city][season].flour_cant,
                    a[city][season].flour_price, a[city][season].yeast_cant,
                    a[city][season].yeast_price, a[city][season].butter_cant,
                    a[city][season].butter_price, a[city][season].sale_value);
            fprintf(stdout, "\n");
        }
    }
}

unsigned int best_profit(BakeryProductTable a) {
  unsigned int max_profit = 0u;
  unsigned int cost = 0u;
  unsigned int sale_value = 0u;
  unsigned int profit = 0u;

  // find best bakery/season profit
  for (unsigned int city = 0u; city < CITIES; ++city)
    {
        for (unsigned int season = 0u; season < SEASONS; ++season)
        {
            cost = (a[city][season].flour_cant *  a[city][season].flour_price) +
                   (a[city][season].yeast_cant *  a[city][season].yeast_price) +
                   (a[city][season].butter_cant *  a[city][season].butter_price);
            sale_value = a[city][season].sale_value;
            profit = sale_value - cost;

            if(profit >= max_profit)
            max_profit = profit;

        }
    }
    return max_profit;
 
}
    


//typedef BakeryProduct BakeryProductTable[CITIES][SEASONS];

void array_from_file(BakeryProductTable array, const char* filepath)
{
    FILE* file = NULL;

    unsigned int scaned_city;
    unsigned int scaned_season;
    BakeryProduct product;

    file = fopen(filepath, "r");
    if (file == NULL)
    {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    
    while (!feof(file))
    {
        int res = fscanf (file, "##%u??%u", &scaned_city,&scaned_season);
        if (res != EXPECTED_DIM_VALUE)
        {
            fprintf(stderr, "Invalid file.\n");
            exit(EXIT_FAILURE);
        }
        product = bakery_product_from_file(file);
        array[scaned_city][scaned_season] = product;
        
    }
    fclose(file);
}
