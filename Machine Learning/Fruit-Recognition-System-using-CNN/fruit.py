from keras.preprocessing.image import ImageDataGenerator
import os
from collections import Counter  # to count the number of classes/labels
import numpy as np  # 2d numpy arrays
import matplotlib.pyplot as plt
from keras.models import Sequential
from tensorflow.keras.layers import Conv2D, MaxPooling2D
from tensorflow.keras.layers import Activation, Dropout, Flatten, Dense
from tensorflow.keras.utils import img_to_array
from tensorflow.keras.preprocessing import image_dataset_from_directory
from tensorflow.keras.utils import load_img
from PIL import Image
from glob import glob
# from google.colab import drive
from pathlib import Path

# Printing all file names under the input directory
for dirname, _, filenames in os.walk('./fruits-360'):
    for filename in filenames:
        print(os.path.join(dirname, filename))

# Setting Training & Test dir paths
train_path = Path("fruits-360/Training")
test_path = Path("fruits-360/Test")

# Displaying the image
img = load_img(str(train_path) + "/Apple Braeburn/0_100.jpg",
               target_size=(100, 100))
plt.imshow(img)
plt.axis("off")
plt.show()
# Printing the shape of the image array
x = img_to_array(img)
print(x.shape)

#Visualizing more Images
images = ['Orange', 'Banana', 'Cauliflower', 'Cactus fruit', 'Eggplant', 'Avocado', 'Watermelon','Lychee', 'Walnut']
fig = plt.figure(figsize =(10,5))
for i in range(len(images)):
    ax = fig.add_subplot(3,3,i+1,xticks=[],yticks=[])
    plt.title(images[i])
    plt.axis("off")
    ax.imshow(load_img(str(train_path) + '/'+ images[i] +"/0_100.jpg", target_size=(100,100)))

# Finding number of classes
className = glob(str(train_path) + '/*')
number_of_class = len(className)
print(number_of_class)

model = Sequential()
# Filter size=32, filter_shape = 3x3
model.add(Conv2D(32, (3, 3), input_shape=x.shape))
model.add(Activation("relu"))
model.add(MaxPooling2D())

model.add(Conv2D(32, (3, 3)))
model.add(Activation("relu"))
model.add(MaxPooling2D())

model.add(Conv2D(64, (3, 3)))  # number of filters= 64
model.add(Activation("relu"))
model.add(MaxPooling2D())

model.add(Flatten())

model.add(Dense(1024))
model.add(Activation("relu"))
model.add(Dropout(0.5))
model.add(Dense(number_of_class))
model.add(Activation("softmax"))

# Compiling the model
model.compile(loss="categorical_crossentropy",
              optimizer="rmsprop",
              metrics=["accuracy"])

# Getting model's summary
model.summary()

epochs = 20 #number of iterations
batch_size = 64 #number of samples that are picked at a time

train_datagen = ImageDataGenerator(rescale=1./255,
                                   shear_range=0.3,
                                   horizontal_flip=True,
                                   zoom_range=0.3)
test_datagen = ImageDataGenerator(rescale=1./255)
# Generating batches of Augmented data.
train_generator = train_datagen.flow_from_directory(
    directory=train_path,
    target_size=x.shape[:2],
    batch_size=batch_size,
    color_mode="rgb",
    class_mode="categorical")
test_generator = test_datagen.flow_from_directory(
    directory=test_path,
    target_size=x.shape[:2],
    batch_size=batch_size,
    color_mode="rgb",
    class_mode="categorical")

hist = model.fit_generator(
    generator=train_generator,
    steps_per_epoch=1600 // batch_size,
    epochs=epochs,
    validation_data=test_generator,
    validation_steps=800 // batch_size)


plt.figure()
plt.plot(hist.history["loss"], label="Train Loss", color="black")
plt.plot(hist.history["val_loss"], label="Validation Loss", color="mediumvioletred",
         linestyle="dashed", markeredgecolor="purple", markeredgewidth=2)
plt.title("Model Loss", color="darkred", size=13)
plt.legend()
plt.show()


img = load_img(str(test_path) + "/Orange/77_100.jpg", target_size=(100, 100))
plt.imshow(img)
plt.axis("off")
plt.show()
# Loading the image


def load(filename):
    np_image = Image.open(filename)
    np_image = np.array(np_image).astype('float32')/255
    np_image = np.expand_dims(np_image, axis=0)
    return np_image


image = load(str(test_path) + "/Orange/77_100.jpg")

img = load_img(str(test_path) + "/Orange/77_100.jpg", target_size=(100, 100))
plt.imshow(img)
plt.axis("off")
plt.show()
# Loading the image


def load(filename):
    np_image = Image.open(filename)
    np_image = np.array(np_image).astype('float32')/255
    np_image = np.expand_dims(np_image, axis=0)
    return np_image


image = load(str(test_path) + "/Orange/77_100.jpg")
