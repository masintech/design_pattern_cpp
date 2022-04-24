#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct HtmlBuilder;

struct HtmlElement {
  string name;
  string text;
  vector<HtmlElement> elements;
  const size_t indent_size = 2;

  HtmlElement() {}
  HtmlElement(const string& name, const string& text)
      : name(name), text(text) {}

  string str(int indent = 0) const {
    ostringstream oss;
    string i(indent_size * indent, ' ');  //  '' * indent_size * indent
    oss << i << "<" << name << ">" << endl;
    if (text.size() > 0)
      oss << string(indent_size * (indent + 1), ' ') << text << endl;
    for (const auto& e : elements) oss << e.str(indent + 1);
    oss << i << "</" << name << ">" << endl;
    return oss.str();
  }

  static unique_ptr<HtmlBuilder> create(string root_name) {
    return make_unique<HtmlBuilder>(root_name); // notice it's a builder returned 
  }
};

struct HtmlBuilder
{
  HtmlBuilder(string root_name)
  {
    root.name = root_name;
  }

  // void to start with
  HtmlBuilder& add_child(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    return *this;
  }

  // pointer based
  HtmlBuilder* add_child_2(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    return this;
  }

  string str() { return root.str(); }
  HtmlElement build() {return root;} // actually return the element
  operator HtmlElement() const { return root; }
  HtmlElement root;
};

int main() {
  // easier
  HtmlBuilder builder{"ul"};
  builder.add_child("li", "hello").add_child("li", "world");
  cout << builder.str() << endl;

  HtmlElement elem = HtmlElement::create("ul")->add_child("","").build();
}