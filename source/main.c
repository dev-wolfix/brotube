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
                res = webConfigSetFooter(&cfg, false);
                res = webConfigSetPageCache(&cfg, true);
                res = webConfigSetWhitelist(&cfg, "^http*");
                res = webConfigSetUserAgentAdditionalString(&cfg, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36");

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
