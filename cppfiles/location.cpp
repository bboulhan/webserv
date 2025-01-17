/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:48:36 by aer-razk          #+#    #+#             */
/*   Updated: 2022/12/12 11:38:39 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/location.hpp"

location::location()
{
}

location::~location()
{
}


std::vector<std::string>	location::checknsearch(std::string var)
{
	std::map<std::string, int> lst;
	lst["root"] = 1;
	lst["allow_methods"] = 3;
	lst["cgi_path"] = 1;
	lst["cgi_extension"] = 1;
	lst["auto_index"] = 1;
	lst["path"] = 1;
	lst["index"] = 1;
	std::vector<std::string> splits;
	if (var == "location")
	{
		if (cont_location[0].find(var) > cont_location[0].length() || cont_location[0].find(var) != 1)
			throw errors("do3afa2:location error.");
		splits = ft_split(cont_location[0], ' ');
		if (splits.size() != 3)
			throw errors("do3afa2:location argument error.");
		splits.erase(splits.begin());
		splits.erase(splits.end() - 1);
		return splits;
	}
	for(int i = 0; i < cont_location.size(); i++)
	{
		if (cont_location[i].find(var) == 2)
		{
			splits = ft_split(cont_location[i], ' ');
			if (splits.size() > lst[var] + 1 && splits[splits.size() - 1] != ";")    
			{
				char echo[30000];
				std::sprintf(echo ,"do3afa2:%s:too many arguments.", var.c_str());
				throw errors(echo);
			}
			break ;
		}
	}
	if (splits.size() == 0)
	{
		return (splits.push_back("") ,splits);
	}
	if (splits[splits.size() - 1][splits[splits.size() - 1].length() - 1] != ';')
		throw errors("do3afa2a:tag is not closed 'missing ;'");     
	splits[splits.size() - 1] = splits[splits.size() - 1].substr(0, splits[splits.size() - 1].length() - 1);
	splits.erase(splits.begin());
	return splits;
}


void		location::set_allow_methods()
{
	std::vector<std::string>    allow_methods_v = this->checknsearch("allow_methods");

	for (int i = 0; i < allow_methods_v.size();i++)
	{
		if (allow_methods_v[i] == "GET")
			this->allow_methods.push_back("GET");
		else if (allow_methods_v[i] == "POST")
			this->allow_methods.push_back("POST");
		else if (allow_methods_v[i] == "DELETE")
			this->allow_methods.push_back("DELETE");
		else
			throw errors("do3afa2:allow_methods bad arguments!");
	}
}

void		location::set_root()
{
	std::vector<std::string> root_p = this->checknsearch("root");
	if (!root_p[0].length())
		throw errors("do3afa2:root is missing in location.");
	this->root = root_p[0];
}

void		location::set_location_path()
{
	std::vector<std::string> splits = this->checknsearch("location");
	if (!splits[0].length())
		throw errors("do3afa2:location is invalid.");
	this->location_path = splits[0];
}

void		location::set_index(bool autoindex)
{
	std::vector<std::string> index_p = this->checknsearch("index");
	if (!index_p[0].length() && autoindex == true)
	{
		this->autoindex = true;
		this->index = "";
		return ;
	}
	else if (!index_p[0].length() && autoindex == false)
		throw errors("do3afa2:missing index while autoindex is off.");
	this->index = index_p[0];
}

std::string	location::get_location_path(void)
{
	return (this->location_path);
}

std::string	location::get_root(void)
{
	return (this->root);
}

std::string	location::get_index(void)
{
	return (this->index);
}

void		location::set_cgi_path()
{
	std::vector<std::string> cgi = checknsearch("index");
	if (!cgi[0].length() && autoindex == true)
	{
		this->autoindex = true;
		this->index = "";
		return ;
	}
	else if (!cgi[0].length() && autoindex == false)
		throw errors("do3afa2:missing index while autoindex is off.");
	cgi_path = cgi[0];
}

void		location::set_cgi_extension()
{
	std::vector<std::string> cgi = checknsearch("cgi_extension");
	if (!index.length() && cgi[0].length())
		throw errors("do3afa2:cgi_extension while index is missing.");
	cgi_extension = cgi[0];
}

std::string	location::get_cgi_path()
{
	return (cgi_path);
}

std::string	location::get_cgi_extension()
{
	return (cgi_extension);
}

bool location::get_autoindex()
{
	return this->autoindex;
}