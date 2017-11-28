#include <iostream>
#include <vector>
#include <stdio.h>          //popen
#include <algorithm>
#include <sys/stat.h>

std::vector<std::string> fcnListFolder(std::string folder)
{
	FILE *in;
    char buff[1024*32];
    std::vector<std::string> list;
    // Importing datalogs
	in = popen(("ls " + folder).c_str(),"r");
	while(fgets(buff, sizeof(buff), in)!=NULL){
        list.push_back(std::string(buff));
	}
    pclose(in);
    for( int i = 0; i < list.size(); i++ )
    {
        list[i].erase (std::remove (list[i].begin(), list[i].end(), '\n'), list[i].end());    
    }

    return list;
}
void fcnMakeFolder (std::string folder)
{
    //std::cout << "fcnMakeFolder: " << folder << std::endl;
    struct stat info;
    stat(folder.c_str(), &info);
    if( info.st_mode & S_IFDIR )  // S_ISDIR() doesn't exist on my windows 
    {
    }
    else
    {
        std::cout << "Do not exist " << folder << std::endl;
        popen(("mkdir " + folder).c_str(), "w");
    }
}
int main( int argc, char* argv[] )
{
	std::vector<std::string> daylist, folderlist, filelist;
    std::string folder = "Data";

    daylist = fcnListFolder(folder);
    for (int i = 0; i < daylist.size(); i++)
    { 
        fcnMakeFolder("Data_new/" + daylist[i]);
        std::cout << "day: " << daylist[i] << " folder\n";
        folderlist = fcnListFolder(folder + "/" + daylist[i]);
        for (int j = 0; j < folderlist.size(); j++)
        {            
            fcnMakeFolder("Data_new/" + daylist[i] + "/" + folderlist[j]);
            std::cout << "folder: " << folderlist[j] << " folder\n";
          
            filelist = fcnListFolder(folder + "/" + daylist[i] + "/" + folderlist[i]);
            for (int k = 0; k < filelist.size(); k++)
            {
                std::cout << "file: " << filelist[k] << " file\n";
            }
        }

    }

}