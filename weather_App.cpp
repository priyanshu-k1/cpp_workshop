#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

class WeatherApp : public QWidget {
    Q_OBJECT

public:
    WeatherApp(QWidget *parent = nullptr) : QWidget(parent) {
        setupUi();
        setupConnections();
    }

private slots:
    void fetchWeather() {
        QString city = cityLineEdit->text();
        QString url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=88c82ccb9683f796bc81905b0694fddd";

        QNetworkRequest request;
        request.setUrl(QUrl(url));

        QNetworkReply *reply = manager.get(request);
        connect(reply, &QNetworkReply::finished, this, &WeatherApp::handleWeatherResponse);
    }

    void handleWeatherResponse() {
        QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
        if (reply && reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
            QJsonObject jsonObj = jsonDoc.object();

            if (jsonObj.contains("main")) {
                QJsonObject mainObj = jsonObj["main"].toObject();
                if (mainObj.contains("temp")) {
                    double temperature = mainObj["temp"].toDouble() - 273.15;
                    temperatureLabel->setText(QString("Temperature: %1°C").arg(temperature));
                }
            }

            if (jsonObj.contains("weather")) {
                QJsonArray weatherArray = jsonObj["weather"].toArray();
                if (!weatherArray.isEmpty()) {
                    QJsonObject weatherObj = weatherArray[0].toObject();
                    if (weatherObj.contains("description")) {
                        QString description = weatherObj["description"].toString();
                        descriptionLabel->setText(QString("Description: %1").arg(description));
                    }
                }
            }
        }

        reply->deleteLater();
    }

private:
    void setupUi() {
        cityLineEdit = new QLineEdit(this);
        fetchButton = new QPushButton("Fetch Weather", this);
        temperatureLabel = new QLabel(this);
        descriptionLabel = new QLabel(this);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(cityLineEdit);
        layout->addWidget(fetchButton);
        layout->addWidget(temperatureLabel);
        layout->addWidget(descriptionLabel);

        setLayout(layout);
    }

    void setupConnections() {
        connect(fetchButton, &QPushButton::clicked, this, &WeatherApp::fetchWeather);
    }

    QLineEdit *cityLineEdit;
    QPushButton *fetchButton;
    QLabel *temperatureLabel;
    QLabel *descriptionLabel;
    QNetworkAccessManager manager;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    WeatherApp weatherApp;
    weatherApp.show();

    return app.exec();
}

#include "main.moc"
