#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <switch.h>

int main(int argc, char* argv[])
{
    consoleInit(NULL);

    while (appletMainLoop())
    {
        if(appletGetAppletType() == AppletType_Application)
        {
            Result res;
            WebCommonConfig cfg;
            res = webPageCreate(&cfg, "https://youtube.com");

            if(R_SUCCEEDED(res))
            {
                res = webConfigSetWhitelist(&cfg, "^http*");

                if(R_SUCCEEDED(res))
                {
                    res = webConfigShow(&cfg, NULL);
                }
                else
                {
                    printf(CONSOLE_RED "Something went wrong.");
                    consoleUpdate(NULL);

                    sleep(3);
                    break;
                }
            }
            else
            {
                printf(CONSOLE_RED "Failed while making WebCommonConfig object.");
                consoleUpdate(NULL);

                sleep(3);
                break;
            }
        }
        else
        {
            printf(CONSOLE_RED "AppletMode is not supported!");
            consoleUpdate(NULL);

            sleep(3);
            break;
        }
    }

    consoleExit(NULL);
    return 0;
}
