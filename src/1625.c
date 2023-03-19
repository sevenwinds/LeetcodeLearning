
// Copyright
// date: 2023-3-19

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *findLexSmallestString(char *s, int a, int b)
{
    int len = strlen(s);
    int vis[len];
    memset(vis, 0, sizeof(vis));
    char *res = (char *)calloc(sizeof(char), len + 1);
    strcpy(res, s);
    char str[2 * len + 1];
    sprintf(str, "%s%s", s, s);
    for (int i = 0; vis[i] == 0; i = (i + b) % len)
    {
        vis[i] = 1;
        for (int j = 0; j < 10; j++)
        {
            int k_limit = b % 2 == 0 ? 0 : 9;
            for (int k = 0; k <= k_limit; k++)
            {
                char t[len + 1];
                strncpy(t, str + i, len);
                t[len] = '\0';
                for (int p = 1; p < len; p += 2)
                {
                    t[p] = '0' + (t[p] - '0' + j * a) % 10;
                }
                for (int p = 0; p < len; p += 2)
                {
                    t[p] = '0' + (t[p] - '0' + k * a) % 10;
                }
                if (strcmp(t, res) < 0)
                {
                    strcpy(res, t);
                }
            }
        }
    }
    return res;
}