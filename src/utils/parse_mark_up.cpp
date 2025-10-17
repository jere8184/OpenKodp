
#include <fstream>
#include <string>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <print>

#include "tinyxml2.h"


using Node = const tinyxml2::XMLNode;
using page = std::unordered_map<std::string, std::string>;
using pages = std::vector<page>;

const tinyxml2::XMLNode* find_xml_node(const tinyxml2::XMLNode* node, const std::string& value)
{
	if (node->Value() == value)
	{
		std::println("found");
		return node;
	}

	const tinyxml2::XMLNode* result = nullptr;

	const tinyxml2::XMLNode* first_child = node->FirstChild();

	if (first_child != nullptr)
		result = find_xml_node(first_child, value);

	if (result == nullptr)
	{
		const tinyxml2::XMLNode* sibling = node->NextSibling();

		if (sibling != nullptr)
			result = find_xml_node(sibling, value);
	}
	return result;
	
};

void parse_xml_document(std::string path)
{
	tinyxml2::XMLDocument document;
	document.LoadFile(path.c_str());
	//parse_xml_nodes(document.FirstChild());

	//std::cout << document.FirstChild()->Value() << std::endl;
	//std::cout << document.FirstChild()->ChildElementCount() << std::endl;
	//std::cout << document.FirstChild()->NextSibling() << std::endl;
}

std::vector<const tinyxml2::XMLNode* const> find_page_nodes(const std::string& path)
{
	tinyxml2::XMLDocument document;
	document.LoadFile(path.c_str());

	tinyxml2::XMLElement* element = document.FirstChildElement();
	const tinyxml2::XMLNode* pages_tag = find_xml_node(element, "pages");


	std::vector<const tinyxml2::XMLNode* const> result;
	if (pages_tag != nullptr)
	{
		const tinyxml2::XMLNode* page_node = pages_tag->Parent()->NextSiblingElement()->FirstChild();

		while (page_node != nullptr && page_node->Value() == "dict")
		{
			result.push_back(page_node);
		}
		
	}

	return result;
}

std::pair<std::string, std::string> extract_key_value()
{

};

pages parse_page_nodes(const std::vector<const tinyxml2::XMLNode* const>& pages_nodes)
{
	for (const tinyxml2::XMLNode* const page_node : pages_nodes)
	{

	}
} 



int main()
{	
	find_page_nodes("Intro.plist");
}