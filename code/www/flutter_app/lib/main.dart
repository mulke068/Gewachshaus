import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;

void main() {
  runApp(const MyApp());
}





class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        title: 'Flutter Demo',
        theme: ThemeData(
          var response = await http.get(Uri.parse('http://localhost/api.php'));
          if (response.statusCode == 200) {
            // Successful response
            var responseBody = response.body;
          } else {
            // Error handling
          }

          var response = await http.post(Uri.parse('http://localhost/api.php'),
            body: {
              'key': 'value',
            },
          );
          if (response.statusCode == 200) {
            // Successful response
          } else {
            // Error handling
          }
          primarySwatch: Color.fromARGB(255, 255, 255, 255),
        ));
  }
}
