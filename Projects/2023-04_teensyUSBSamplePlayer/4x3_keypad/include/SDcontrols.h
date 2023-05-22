
void SD_info();

void SD_save_file_list(std::vector<char*> file_list);

void readSD(std::vector<String> file_list);

void printDirectory(File dir, int numTabs, std::vector<String> file_list);

void printDirectory(File dir, int numTabs);