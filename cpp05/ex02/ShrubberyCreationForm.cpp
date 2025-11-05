/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saabo-sh <saabo-sh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:34:23 by saabo-sh          #+#    #+#             */
/*   Updated: 2025/10/25 16:58:15 by saabo-sh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

static const int SIGN_GRADE = 145;
static const int EXEC_GRADE  = 137;

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", SIGN_GRADE, EXEC_GRADE), target("default")
{
     std::cout << "ShrubberyCreationForm: default constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t)
    : AForm("ShrubberyCreationForm", SIGN_GRADE, EXEC_GRADE), target(t)
{
    std::cout << "ShrubberyCreationForm: constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm: destructor called\n";
}

static void printDirectory(std::ofstream& out, const std::string& path, const std::string& prefix)
{
    DIR* dir = opendir(path.c_str());
    if (!dir) return;

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        std::string name = entry->d_name;

        // Skip "." and ".."
        if (name == "." || name == "..")
            continue;

        std::string fullPath = path + "/" + name;

        struct stat info;
        if (stat(fullPath.c_str(), &info) != 0)
            continue;

        // Print current entry
        out << prefix << "|-- " << name << "\n";

        // If directory, recurse
        if (S_ISDIR(info.st_mode)) {
            printDirectory(out, fullPath, prefix + "    ");
        }
    }

    closedir(dir);
}

void ShrubberyCreationForm::executeAction() const
{
    std::string filename = target + "_shrubbery";
    std::ofstream outfile(filename.c_str());

    if (!outfile) {
        std::cerr << "ShrubberyCreationForm: could not create file '" << filename << "'\n";
        return;
    }
    printDirectory(outfile, ".", "");

    outfile.close();

    std::cout << "ShrubberyCreationForm: directory tree saved in '" << filename << "' successfully.\n";
}


