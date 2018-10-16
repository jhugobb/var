using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class grab : MonoBehaviour
{

    public Transform MyHand;
    public Rigidbody objMovible;
    public bool inPlace = false;


    public void take()
    {
        if (!inPlace)
        {
            objMovible.transform.parent = MyHand.transform;
            objMovible.transform.localPosition = MyHand.transform.localPosition;
            objMovible.isKinematic = true;
            objMovible.detectCollisions = false;
            inPlace = true;
        }

    }
}
