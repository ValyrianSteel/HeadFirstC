#include <stdio.h>

struct exercise {
  const char *description;
  float duration;
};

struct meal {
  const char *ingredients;
  float weight;
};

struct preferences {
  struct meal food;
  struct exercise exercise;
};

struct fish {
  const char *name;
  const char *species;
  int teeth;
  int age;
  struct preferences care;
};

void catalog(struct fish f)
{
  printf("%s is a %s with %i teeth. He is %i\n", f.name, f.species, f.teeth, f.age);
}

void label(struct fish f)
{
  printf("Name: %s\nSpecies: %s\n%i years old, %i teeth\n", f.name, f.species, f.teeth, f.age);
  printf("Feed with %2.2f lbs of %s and allow to %s for %2.2f hours\n", f.care.food.weight, f.care.food.ingredients, f.care.exercise.description, f.care.exercise.duration);
}

int main()
{
  struct fish snappy = {"Snappy", "Piranha", 69, 4, {{"meat", 0.2}, {"swim in the jacuxxi", 7.5}}};
  catalog(snappy);
  label(snappy);

}
