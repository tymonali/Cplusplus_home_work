#include "Move.h"

bool Move::moveDir(string pathFrom, string pathTo)
{
	bool doRewrite = false, doDelete = false;
	_finddata_t* infoFrom = new _finddata_t;
	_finddata_t* infoTo = new _finddata_t;
	string pathFind, newPathFrom, newPathTo;
	pathFind = pathTo;
	_mkdir(pathTo.c_str());
	pathFind += "\\*.*";
	long findHandleFrom = _findfirst(pathFind.c_str(), infoFrom), findHandleTo;
	long isExist = findHandleFrom;

	string dot = ".", dotdot = "..";
	while(isExist != -1)
	{
		newPathFrom = pathFrom;
		newPathTo = pathTo;
		if(dot.compare(infoFrom->name) !=0 && dotdot.compare(infoFrom->name) != 0)
		{
			newPathFrom += "\\";
			newPathFrom += infoFrom->name;
			newPathTo += "\\";
			newPathTo += infoFrom->name;
			if (infoFrom->attrib & _A_SUBDIR)
			{
				if (!moveDir(newPathFrom, newPathTo))
				{
					return false;
				}
			}
			else
			{
				findHandleTo = _findfirst(newPathTo.c_str(), infoTo);
				if (!rewriteForAll && findHandleTo != -1)
				{
					switch(rewriteMenu(newPathTo))
					{
					case CANCEL:
						return false;
					case REWRITE:
						doRewrite = true;
					case SKIP:
						break;
					case REWRITEFORALL:
						rewriteForAll = true;
					default:
						break;
					}
				}
				if (!deleteForAll && (infoFrom->attrib & _A_RDONLY))
				{
					switch (deleteMenu(newPathFrom))
					{
					case CANCEL:
						return false;
					case REMOVE:
						doDelete = true;
						break;
					case SKIP:
						break;
					case REMOVEFORALL:
						deleteForAll = true;
					default:
						break;
					}
				}
				if(findHandleTo == -1 || (findHandleTo != -1 && (doRewrite || rewriteForAll)))
				{
					if (!(infoFrom->attrib & _A_RDONLY) || doDelete || deleteForAll)
					{
						_chmod(newPathFrom.c_str(), _S_IWRITE);
						remove(newPathTo.c_str());
						rename(newPathFrom.c_str(), newPathTo.c_str());
					}
					else
					{
						copyFile(newPathFrom.c_str(), newPathTo.c_str());
					}
				}
				_findclose(findHandleTo);
			}
		}
		isExist = _findnext(findHandleFrom, infoFrom);
	}
	_findclose(findHandleFrom);
	_rmdir(pathFrom.c_str());
	return true;
}

void Move::copyFile(string output, string input)
{
	FILE* inputFile, * outputFile;
	fopen_s(&outputFile, output.c_str(), "r");
	fopen_s(&inputFile, input.c_str(), "w");
	char buffer[255];
	if (outputFile && inputFile)
	{
		while (!feof(outputFile))
		{
			fgets(buffer, 255, outputFile);
			fputs(buffer, inputFile);
		}
	}
}

int Move::rewriteMenu(string fileName)
{
	int act;
	do
	{
		cout << "File " << fileName << " is exist. Do you want to do?\n";
		cout << "0 - Cancel;\n";
		cout << "1 - Rewrite;\n";
		cout << "2 - Skip;\n";
		cout << "3 - Rewrite all next file.\n";
		cin >> act;
	} while (act < 0 || act>3);
	return act;
}

int Move::deleteMenu(string fileName)
{
	int act;
	do
	{
		cout << "File " << fileName << " is Read-Only. Do you want to do?\n";
		cout << "0 - Cancel;\n";
		cout << "1 - Delete;\n";
		cout << "2 - Skip;\n";
		cout << "3 - Delete all next file.\n";
		cin >> act;
	} while (act < 0 || act>3);
	return act;
}
