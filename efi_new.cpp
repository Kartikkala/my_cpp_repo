#include <iostream>
#include <string>
#include <stdexcept>
#include <filesystem>

bool signEfiFile(const std::string& filePath) {
    // Construct the sbctl command to sign the EFI file.
    std::string cmd = "sbctl sign --key-file /path/to/private/key.pem --output-file ";
    cmd += filePath + ".signed " + filePath;
    
    int result = system(cmd.c_str());
    if (result == -1) {
        perror("Failed to execute sbctl command");
        return false;
    }
    
    std::cout << "Signed: " << filePath << std::endl;
    return true;
}

void findAndSignEfiFiles(const std::string& directory, const std::string& pattern) {
    for (const auto & entry : std::filesystem::recursive_directory_iterator(directory)) 
{
        if (!entry.is_regular_file() || entry.path().extension() != pattern)
            continue;

        signEfiFile(entry.path().string());
    }
}

int main(char *argv[], int argc) {
    try {
        const std::string startDirectory = "/"; // Start at the root directory
        const std::string filePattern = ".efi";

        findAndSignEfiFiles(startDirectory, filePattern);
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}