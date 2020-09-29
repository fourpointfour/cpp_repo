import 'dart:async';
import 'dart:io' as IO;
import 'dart:convert';

Future<void> getData(areas, locations) async {
  var request = await IO.HttpClient()
      .getUrl(Uri.parse('http://worldtimeapi.org/api/timezone.txt'));
  var response = await request.close();
  var value = "";
  await for (var contents in response.transform(Utf8Decoder())) {
    value += contents;
  }
  List<String> urls = value.split('\n');
  urls.forEach((item) {
    List<String> prop = item.split('/');
    areas.add(prop[0]);
    final key = prop[0];
    if (prop.length > 1) {
      locations[key] =
          (locations[key] == null) ? List<String>() : locations[key];
      locations[key].add(prop[1]);
    } else
      locations[key] = List<String>();
  });

  // print('areas are $areas');
}

void main() async {
  var areaFile = new IO.File('areaJson.json');
  var locationFile = IO.File('locJson.json');
  print("Started");
  List<String> areas = [];
  Map<String, List<String>> locations = {};
  await getData(areas, locations);
  // await areaFile.writeAsString(areas, mode: IO.FileMode.write);
  areas = Set<String>.from(areas).toList();
  var x = jsonEncode(areas);
  var sink = areaFile.openWrite();
  sink.write(x);
  sink.close();
  x = jsonEncode(locations);
  sink = locationFile.openWrite();
  sink.write(x);
  sink.close();
  print('File written successfully');
  // var mapFile = IO.File('locations.txt');
  // sink = mapFile.openWrite(locations);
}
