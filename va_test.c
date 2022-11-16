#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/* Renvoie la moyenne des valeurs réelles passées en
   paramètres. Le premier paramètre, le nombre de valeurs,
   doit être strictement positif. Les suivants doivent être
   des nombres réels (de type float ou double, pas int)  */
void moyenne(char *args, ...)
{
    int s;
    char *str = args;
    va_list params; // pointeur de la liste des paramètres
    va_start(params, args); // initialise le pointeur grâce
    // au dernier paramètre fixe
    int i = 0;


    for (int i = 0 ; i < 3 ; ++i) {
        // récupérer le paramètre suivant de la liste:
        if (i == 0)
        {
            printf("%s\n", str);
        }
        else
        {
            s = va_arg(params, int);
            //printf("%d\n", s);
        }
        //double valeur_suiv = va_arg(params, double);
        //somme += valeur_suiv;
    }
    va_end(params); // fermeture de la liste
    //return somme / nb_valeurs;
}

int main(void)
{       // exemple d'utilisation :;
    int i= 4489;

    char t[500];

	while (i != 0)
	{
		i % 16
	}
    printf("%p", (void *)o);

    return 0;
}
