#include <iostream>
#include <string>

using namespace std;

class MediaFile {
public:
    string filePath;
    int size;

    MediaFile(string filePath, int size) : filePath(filePath), size(size) {}

    virtual void play() {
        cout << "Playing " << filePath << endl;
    }

    virtual void stop() {
        cout << "Stopping " << filePath << endl;
    }

    virtual ~MediaFile() = default;
};

class VisualMedia : virtual public MediaFile {
public:
    string resolution;

    VisualMedia(string filePath, int size, string resolution)
        : MediaFile(filePath, size), resolution(resolution) {}

    virtual void display() {
        cout << "Displaying " << filePath << " at " << resolution << " resolution." << endl;
    }

    virtual ~VisualMedia() = default;
};

class AudioMedia : virtual public MediaFile {
public:
    int sampleRate;

    AudioMedia(string filePath, int size, int sampleRate)
        : MediaFile(filePath, size), sampleRate(sampleRate) {}

    virtual void playAudio() {
        cout << "Playing audio from " << filePath << " at " << sampleRate << "Hz." << endl;
    }

    virtual ~AudioMedia() = default;
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string filePath, int size, string resolution, int sampleRate)
        : MediaFile(filePath, size), VisualMedia(filePath, size, resolution), AudioMedia(filePath, size, sampleRate) {}

    void play() override {
        cout << "Playing video with audio: " << filePath << endl;
        playAudio();  
        display();    
    }

    void stop() override {
        cout << "Stopping video: " << filePath << endl;
    }

    virtual ~VideoFile() = default;
};

int main() {
    AudioMedia audioFile("audio.mp3", 10, 44100);
    VisualMedia imageFile("image.jpg", 5, "1920x1080");
    VideoFile videoFile("movie.mp4", 700, "1920x1080", 48000);

    MediaFile* mediaFiles[] = { &audioFile, &imageFile, &videoFile };

    for (MediaFile* media : mediaFiles) {
        media->play();  
        media->stop();
    }

    return 0;
}
