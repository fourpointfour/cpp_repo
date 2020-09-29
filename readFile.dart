import 'dart:convert';
import 'dart:io';

void main() async {
  var loc = await File('areaJson.json');
  var sink = await loc.readAsString();
  List st = jsonDecode(sink);
  print(st);
}
